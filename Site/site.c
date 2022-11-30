#include <stdio.h>
#include <mysql.h>
#include <stdlib.h>

static void print_http_header (const char * content_type)
{
    printf ("Content-Type: %s\n\n", content_type);
}

int main()
{
    MYSQL *con = mysql_init(NULL);
    MYSQL_RES* result;
    MYSQL_ROW row;
    
    print_http_header("text/html");
    printf("<TITLE>Labo3GillesD</TITLE>\n");
    printf("<style><style>#myTable {font-family: Arial, Helvetica, sans-serif;border-collapse: collapse;width: 100%;}#myTable td, #myTable th {border: 1px solid #ddd;padding: 8px;}#myTable tr:nth-child(even){background-color: #f2f2f2;}#myTable tr:hover {background-color: #ddd;}#myTable th {padding-top: 12px;padding-bottom: 12px;text-align: left;background-color: #04AA6D;color: white;}</style></style>");

    if (con == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		exit(1);
	}

	if (mysql_real_connect(con, "localhost", "labo3GillesDurnez", "labo2GillesDurnezPW", "LABO3GillesD", 0, NULL, 0) == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}
    
    printf("<body>");
    printf("<table id=\"myTable\">");
    printf("<tr>");
    printf("<th>Temperatuur</th>");
    printf("<th>Time</th>");
    printf("</tr>");
    // Get data from DB
    mysql_query(con, "SELECT * FROM templogger");
    result = mysql_store_result(con);
    while((row = mysql_fetch_row(result)))
    {
        printf("<tr><td>%s</td><td>%s</td></tr>",row[0],row[1]);
    }
    printf("</table>");
    printf("</body>");
    return 0;
}