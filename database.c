#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

// Parameters to connect to the azure server.
const char *host = "valgroup1mysqlserver.mysql.database.azure.com";
const char *user = "group1member@valgroup1mysqlserver";
const char *pass = "Valgroup1";
const char *dbname = "Group1Database";

unsigned int port = 3306;
const char *unix_socket = NULL;
unsigned int flag = 0;

int main(){

	// Variables
	// Establised the variable for the server connection.
	MYSQL *conn;

	// Choice for the switch.
	char choice = '\0';

	// Initializes the server connecttion.
	conn = mysql_init(NULL);

	// Attemps connection - if unsuccessful, displays error message.
	if(!(mysql_real_connect(conn, host, user, pass, dbname, port, unix_socket, flag))){
		fprintf(stderr, "\nError: %s [%d]\n", mysql_error(conn), mysql_errno(conn));
		exit(1);
 }
	// Displays success message; runs rest of the program.
	printf("Connection Successful!\n\n");
	printf("Database Menu\n\n");

	// Do while to run the program until user decides to stop.
	do{
		// Output - Menu
		printf("Please select one of the following:\n\n");
		printf("(C)ustomer Table\n");
		printf("(O)rder History\n");
		printf("E(X)it.\n\n");
		printf("Enter your choice: ");
		scanf(" %c", &choice, 1);
		printf("\n");

		// Menu
		switch(choice){
			case 'C':
			case 'c':
				// Runs the query for the customers table.
				printf("ID Username FistName LastName Address\n");
				mysql_query(conn, "SELECT * FROM customers");
				MYSQL_RES *customerResult = mysql_store_result(conn);
				int customerNum_fields = mysql_num_fields(customerResult);
				MYSQL_ROW customerRow;
				while((customerRow = mysql_fetch_row(customerResult))){
					for(int i = 0; i < customerNum_fields; i++){
						printf("%s ", customerRow[i] ? customerRow[i] : "NULL");
					}
				  printf("\n\n");
				}
				mysql_free_result(customerResult);
				break;
			case 'O':
			case 'o':
				// Runs the query for the order history table.
				printf("ID ProductId LastName OrderDate\n");
				mysql_query(conn, "SELECT * FROM orderhistory");
				MYSQL_RES *orderResult = mysql_store_result(conn);
				int orderNum_fields = mysql_num_fields(orderResult);
				MYSQL_ROW orderRow;
				while((orderRow = mysql_fetch_row(orderResult))){
					for(int i = 0; i < orderNum_fields; i++){
						printf("%s ", orderRow[i] ? orderRow[i] : "NULL");
					}
				 printf("\n\n");
				}
				mysql_free_result(orderResult);
				break;
			case 'X':
			case 'x':
				// Closes the connection and exits the program.
				mysql_close(conn);
				printf("Have a great day!\n");
				break;
			default:
				// Error
				printf("Error: Invalid choice\n\n");
  }
 } while(choice != 'x' && choice != 'X');

	return EXIT_SUCCESS;

}

