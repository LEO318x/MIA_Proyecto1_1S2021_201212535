#ifndef MBR_H
#define MBR_H
#include "time.h"



typedef struct partition
{
    char part_status;
    char part_type;
    char part_fit;
    int  part_start;
    int  part_size;
    char part_name[16];
};

typedef struct MBR
{
    int mbr_tamano;
    char mbr_fecha_creacion[18];
    int  mbr_disk_signature;
    char disk_fit;
    partition mbr_partition[4];    
};


class mbr
{
private:

public:
    mbr();    
};

#endif // MBR_H
