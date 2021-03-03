

typedef struct superbloque
{
    int s_filesystem_type;
    int s_inodes_count;
    int s_blocks_count;
    int s_free_blocks_count;
    int s_free_inodes_count;
    char s_mtime[16];
    char s_untime[16];
    int s_mnt_count;
    int s_magic = 0xEF53;
    int s_inode_size;
    int s_block_size;
    int s_first_ino;
    int s_first_blo;
    int s_bm_inode_start;
    int s_bm_block_start;
    int s_inode_start;
    int s_block_start;
};

typedef struct inodo
{
    int i_uid;
    int i_gid;
    int i_size;
    char i_atime[16];
    char i_ctime[16];
    char i_mtime[16];
    int i_block[15];
    char i_type;
    int i_perm;
};

typedef struct carpeta
{
    char b_name[12];
    int b_inodo;
};


typedef struct bloqueCarpeta
{
    carpeta b_content[4];
};

typedef struct archivo
{
    char b_content[64];
};

typedef struct apuntador
{
    int b_pointers[16];
};

typedef struct journal{
    char j_tipo_operacion[10];
    char j_tipo;
    char j_nombre[200];
    char j_contenido[200];
    char j_fecha[16];
    char j_propietario[10];
    int j_permisos;
};


