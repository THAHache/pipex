 DOCUMENTACIÓN PARA PIPEX

## Según el subject
	* El nombre del programa será *pipex*.
	* Los archivos a entregar serán el **Makefile** para la compilación, archivos **\*.h** y **\*.c** necesarios.
	* LIBFT y GNL (opcional) para completar el proyecto.
	* Funciones permitidas:
		·open	·close	·read	·write		·access	·execve
		·malloc	·free	·perror	·strerror	·dup	·dup2
		·exit	·fork	·pipe	·unlink		·wait	·waitpid

## Parte oblligatoria
	* El programa deberá ejecutarse de la siguiente forma:
		´./pipex archivo1 comando1 comando2 archivo2´
	* Deberá utilizar 4 argumentos:
		- archivo1 y archivo2 son nombres de archivos
		- comando1 y comando2 son comandos de shell
	* La ejecución del programa pipex deberá hacer lo mismo que el siguiente comando:
		$> < archivo1 comando1 comando2 > archivo2
		- El caracter '<' selecciona el archivo1 como objetivo del comando1
		- El pipeline('|') permite conectar la salida del comando1 con el comando2, convirtiéndola en su entrada
		- El caracter '>' redirige la salida del comando2 al archivo2 y lo sobrescribe con el resultado

## Llamadas al sistema
	* Gestión de ficheros
		- Open
			- Acceso a un fichero existente para leerlo y/o escribir sobre él
			- Sintaxis =>	´int open (const char *nombre, int modo, */mode_t permisos/*);´
			- Devuelve =>	**-1** si hay error
							el número de fd asociado al fichero
			- Modos. Se pueden utilizar varios a la vez separándolos con un OR **|**
				- O_RDONLY	(0)	El fichero se abre para lectura
				- O_WRONLY	(1)	El fichero se abre para escritura
				- O_RDWR	(2)	El fichero se abre para lectura y escritura
				- O_CREAT	Se crea el fichero si no existe
				- O_EXCL	La llamada falla si el fichero existe cuando se combina con O_CREAT
				- O_TRUNC	Si el archivo existe, lo trunca a 0 borrando la información.
				- O_APPEND	El puntero del archivo apunta al final del mismo
		- Close
			- Cerrar un archivo al que ya no se va a acceder
			- Sintaxis =>	´int close (int fd);´
			- Devuelve =>	**0** si cierra el archivo
							**1** si no cierra el archivo
		- Read
			- Leer un archivo abierto
			- Sintaxis =>	´size_t read (int fd, const void *dato, size_t bytes);´
			- Devuelve =>	El número de caracteres leidos
							**-1** si hay error
			- El puntero del fichero quedará indicando el siguiente byte a leer. Tras la operación se avanza el puntero.
		- Write
			- Escritura de datos en un fichero
			- Sintaxis =>	´size_t write (int fd, const void *dato, size_t bytes);´
			- Devuelve =>	El número de caracteres escritos
							Un valor negativo si hay un error
		- Access
			- Comprobación de los permisos de un archivo
			- Sintaxis =>	´int access (const char *ruta, int modo);´
			- Devuelve =>	**0** si se tiene permiso
							**-1** si hay error
			- Modos
				- F_OK	El archivo existe
				- R_OK	El archivo se puede leer
				- W_OK	El archivo puede ser escrito
				- X_OK	El archivo se puede ejecutar
		- Unlink
			- Borra un nombre de un archivo
			- Sintaxis =>	´int unlink (const char *ruta)´
			- Si el nombre del archivo es el último enlace y no hay ningún proceso utilizándolo, lo elimina; si algún proceso aun lo tiene abierto, el archivo seguirá existiendo hasta que se cierre su fd
	* Gestión de procesos
		- Hay una jerarquía de procesos. Un proceso hijo aparece porque otro (padre) lo genera mediante una llamada al sistema. Podemos clasificar las clases de llamadas por funciones:
			- Generar y controlar procesos: fork, wait, waitpid, exit
			- Reiniciar el código del proceso: execve
			- Comunicar entre procesos: pipe, dup, dup2
		- Fork
			- Crear un nuevo proceso
			- Sintaxis =>	´int pid = fork();´
			- Devuelve =>	0 si es el hijo
							PID del hijo si es el padre
			- Si un proceso lo ejecuta, se crea otro proceso que será una copia. Todo será igual hasta el punto de creación, pero continuará la ejecución por serparado, haciéndolo diferente.
		- Wait
			- Espera a que termine el proceso hijo
			- Sintaxis =>	´pid_t wait (int *estado);´
			- Devuelve =>	el valor del PID del proceso que acaba
			- El proceso padre se desbloqueará cuando el hijo termine
		- Waitpid
			- Espera a que termine el proceso hijo especificado por PID
			- Sintaxis =>	´pid_t waitpid (pid_t pid, int *estado, int opciones);´
			- Devuelve =>	PID del proceso hijo
			- Opciones:
				- WNOHANG	vuelve inmediatamente si ningún hijo acaba
				- WUNTRACED	vuelve si hay hijos parados y no ha recibido una notificación
		- Exit
			- Terminar un proceso
			- Sintaxis =>	´void exit (int estado);´
			- Indica al SO la terminación del proceso. Cierra los FD abiertos. Si el proceso padre ejecutó una llamada wait, se activa.
		- Execve
			- Ejecuta el programa que le viene dado por la ruta del comando
			- Sintaxis =>	´int execve (const char *ruta_comando, const char **argumento, const char **environ)´
			- La ruta del comando es donde se encuentra el programa que se va a ejecutar.
			- Los argumentos, al igual que en un main, es la lista de argumentos que ha de evaluar encabezados por el nombre del programa.
			- En la variable environ se guardan las cadenas del tipo ´nombre = valor´. Se usará en **NULL** para el programa.
		- Pipe
			- Comunicación entre procesos
			- Sintaxis =>	´int pipe (int descriptor[2]);´
			- Las dos posiciones del descriptor son:
				- descriptor[0]	para leer datos de la tubería (en orden de llegada)
				- descriptor[1]	para escribir datos en la tubería. Cuando se cierra, se introduce un EOF.
		- Dup
			- Duplica el FD
			- Sintaxis =>	´int dup (int fd);´
			- Devuelve =>	el número del nuevo descriptor. Usa el número de FD más bajo posible
		- Dup2
			- Duplica el FD en un FD específico
			- Sintaxis =>	´int dup2 (int src_fd, int dst_fd);´
			- Si el dst_fd estaba abierto, se cierra silenciosamente
			- Si src_fd no es válido, falla la llamada y dst_fd no se cierra
			- Si src_fd es válido y dst_fd tiene el mismo valor, dup2 no hace nada y devuelve dst_fd
	* Impresión de errores
		- Perror
			- muestra un mensaje correspondiente a un error del sistema
			- Sintaxis =>	´void perror (const char *mensaje);´
			- Produce un mensaje que va a la salida estandar de errores, describiendo el último error encontrado en una llamada al sistema
			- La cadena pasada como argumento debería incluir el nombre de la función donde ocurrió el error. El código de error se toma de la variable externa **errno**
		- Strerror
			- Cadena donde se guarda el mensaje de error
			- Sintaxis =>	´char *strerror(int errnum);´
			- Similar a perror, con la peculiaridad de poder personalizar el mensaje de error.
