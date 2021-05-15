typedef struct ListaNo {
    struct ListaNo* proximo;
    int tamanho_dados;
    void* dados;
} ListaNo;

typedef struct Lista {
    ListaNo* inicio;
    ListaNo* fim;
    int tamanho;
} Lista;