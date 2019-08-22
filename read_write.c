#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "read_write.h"
#include "address.h"

int register_read(uint32_t addr)
{
    volatile uint32_t re_value;
    /*打开mem的这个虚拟设备*/
    int fd;
    fd = open("/dev/mem", (O_RDONLY | O_SYNC));
    if (fd < 0)
    {
        printf("open fail\n");
        exit(1);
    }

    /*mmap函数的调用*/
    uint32_t *mare_base;
    volatile off_t target;
    target = addr;
    mare_base = (unsigned char *)mmap(NULL, DEVMEM_MAP_SIZE, PROT_READ, MAP_SHARED, fd, target & ~DEVMEM_MAP_MASK);
    /*用mmap的函数返回值，判断是否申请虚拟地址成功*/
    if (mare_base == MAP_FAILED)
        printf("MAP_FAILED\n");

    volatile uint32_t i;
    i = (target - CONTROLMODETRIGGER) / 4;
    re_value = *(mare_base + i);

    /* 删除分配的虚拟地址 */
    if (munmap(mare_base, DEVMEM_MAP_SIZE) == -1)
        printf("DEVMEM_MAP_SIZE\n");

    close(fd);
    return re_value;
}

void register_write(uint32_t addr, uint32_t write_data)
{
    uint32_t *map_base, *virt_addr;
    uint64_t writeval = write_data;

    /*打开mem的这个虚拟设备*/
    int fd;
    fd = open("/dev/mem", (O_RDWR | O_SYNC));
    if (fd < 0)
    {
        printf("open fail\n");
        exit(1);
    }

    /*mmap函数的调用*/
    off_t target;
    target = addr;
    map_base = (unsigned char *)mmap(NULL, DEVMEM_MAP_SIZE, (PROT_READ | PROT_WRITE), MAP_SHARED, fd, target & ~DEVMEM_MAP_MASK);
    if (map_base == MAP_FAILED)
        printf("MAP_FAILED\n");

    volatile uint32_t i;
    i = (target - CONTROLMODETRIGGER) / 4;
    virt_addr = map_base + i;
    *(volatile uint32_t *)virt_addr = writeval;

    if (munmap(map_base, DEVMEM_MAP_SIZE) == -1)
        printf("DEVMEM_MAP_SIZE\n");
    close(fd);
}