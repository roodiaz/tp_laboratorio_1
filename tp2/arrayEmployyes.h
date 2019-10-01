
typedef struct
{
    int idSector;
    char nombreSector[21];
} eSector;

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} eEmployee;

int menuABM();

int menuModificacion();

int menuSectores();

int menuInformes();

void inicializarEmpleados(eEmployee vec[], int tam);

int buscarLibre(eEmployee vec[], int tam);

int buscarId(int id, eEmployee vec[], int tam);

int buscarNombreSector(int id, eSector vec[], int tam, char dondeAsignar[]);

void mostrarDato(eEmployee vec, eSector vecS[], int tamS);

void mostrarDatos(eEmployee vec[], int tam, eSector vecS[], int tamS);

int hardCodeo(eEmployee vec[], int tam,int cantidad);

int altaEmpleado(eEmployee vec[], int tam, int id, eSector vecS[], int tamS);

int modificarEmpleado(eEmployee vec[], int tam, eSector vecS[], int tamS);

void bajaEmpleado(eEmployee vec[], int tam, eSector vecS[], int tamS);

void ordenarEmpleados(eEmployee vec[], int tam);

void promedioTotal(eEmployee vec[], int tam);


void informes(eEmployee vec[], int tam, eSector vecS[], int tamS);
