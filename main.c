#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

struct CELL {
	char website[60];
	char username[60];
	char password[60];
} cells[3];

int main() {
	FILE *cll;
	char ch;
	uint8_t cell;
	if (getuid() != 0) {
		printf("Error, user needs to be root !");
		return -1;
	}
	printf("Welcome to PasswordManagerLinux (Alpha)\n");
	system("touch /.cell1 && touch /.cell2  && touch /.cell3 > /dev/null");
	printf("e - Edit a Cell, r - Read a Cell\n");
	scanf("%c", &ch);
	if (ch == 'e') {
		printf("What cell to edit: ");
		scanf("%hhu", &cell);
		if (cell > 3) {
			printf("Error ! Only 3 cells avaible\n");
			return -1;
		}
		printf("=================\n");
		if (cell == 1) {
			cll = fopen("/.cell1", "w+");
			printf("Enter what website: ");
			scanf("%s", cells[cell-1].website);
			fprintf(cll, "website: %s\n", cells[cell-1].website);
			printf("Enter what username: ");
			scanf("%s", cells[cell-1].username);
			fprintf(cll, "username: %s\n", cells[cell-1].username);
			printf("Enter what password: ");
			scanf("%s", cells[cell-1].password);
			fprintf(cll, "password: %s\n", cells[cell-1].password);
			fclose(cll);
			printf("All done !\n");
		}
		else if (cell == 2) {
			cll = fopen("/.cell2", "w+");
			printf("Enter what website: ");
			scanf("%s", cells[cell-1].website);
			fprintf(cll, "website: %s\n", cells[cell-1].website);
			printf("Enter what username: ");
			scanf("%s", cells[cell-1].username);
			fprintf(cll, "username: %s\n", cells[cell-1].username);
			printf("Enter what password: ");
			scanf("%s", cells[cell-1].password);
			fprintf(cll, "password: %s\n", cells[cell-1].password);
			fclose(cll);
			printf("All done !\n");
		}
		else if (cell == 3) {
			cll = fopen("/.cell3", "w+");
			printf("Enter what website: ");
			scanf("%s", cells[cell-1].website);
			fprintf(cll, "website: %s\n", cells[cell-1].website);
			printf("Enter what username: ");
			scanf("%s", cells[cell-1].username);
			fprintf(cll, "username: %s\n", cells[cell-1].username);
			printf("Enter what password: ");
			scanf("%s", cells[cell-1].password);
			fprintf(cll, "password: %s\n", cells[cell-1].password);
			fclose(cll);
			printf("All done !\n");
		}
		else {
			printf("Invalid option !\n");
			return -1;
		}
	}
	else if (ch == 'r') {
		printf("What cell to read: ");
		scanf("%hhu", &cell);
		if (cell > 3) {
			printf("Error ! Only 3 cells avaible\n");
			return -1;
		}
		printf("=================\n");
		if (cell == 1) {
			system("cat /.cell1");

		}
		else if (cell == 2) {
			system("cat /.cell2");
		}
		else if (cell == 3) {
			system("cat /.cell3");
		}
	}
	return 0;
}
