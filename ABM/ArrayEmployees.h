typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int sector;
    int ocupado;

}eEmpleado;


/** \brief Menu de opciones ABM
 *
 * \param Muestra opcines a elegir
 * \return Opcion elegida
 *
 */
int menuABM();


/** \brief Pone a todos los empleados en estado 0
 *
 * \param Ingresar vector
 * \param Ingresar tamaño del vector
 * \return Nada
 *
 */
void inicializarEmpleados(eEmpleado vec[], int tam);


/** \brief Busca espacio libre para dar de alta empleado
 *
 * \param Ingresar vector
 * \param Ingresar tamaño del vector
 * \return Nada
 *
 */
int buscarLibre(eEmpleado vec[], int tam);


/** \brief
 *
 * \param Ingresar vector
 * \param Ingresar tamaño del vector
 * \return Numero de empleado
 *
 */
int buscarEmpleado(eEmpleado vec[], int tam, int id);


/** \brief Opciones para dar de alta un empleado
 *
 * \param Ingresar vector
 * \param Ingresar tamaño del vector
 * \return Nada
 *
 */
void altaEmpleado(eEmpleado vec[], int tam);


/** \brief Muestra informacion de un empleado
 *
 * \param Estructura de empleados
 * \return Nada
 *
 */

void mostrarEmpleado(eEmpleado empleado);
