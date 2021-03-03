#ifndef MBR_H
#define MBR_H
#include "time.h"



typedef struct
{
    char part_status;
    char part_type;
    char part_fit;
    int  part_start;
    int  part_size;
    char part_name[16];
}Partition;

typedef struct
{
    int mbr_tamano;
    char mbr_fecha_creacion[16];
    int  mbr_disk_signature;
    char disk_fit;
    Partition mbr_partition[4];    
}MBR;


class mbr
{
private:

public:
    mbr();    
};

#endif // MBR_H
