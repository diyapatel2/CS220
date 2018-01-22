/* Prog.c */
#include <stdio.h>
void bad()
{
	/*your implementation goes here */
	char *new_name = "Quick brown fox jumped over the lazy dog";
	unsigned char *temp;
	temp = (unsigned char *) (&new_name); //initialize temp to address of new_name
	*((unsigned long *) (temp + 0x30)) += 0x20;
	/*Treat as it temp+offset_name contains an address to string and set the address to the new_STring as the contents of the location */
	*((char **) (temp + 0x20)) = new_name; 
	/* Treat as if temp+offset_age is a pointer to an integer and store the value 1000 in the location pointed to by that integer */
	*((int *) (temp + 0x28)) = 1000;
}

int main(){
	struct {
		char *name;
		int age; 
	} student = {.name = "John", .age = 22};
	bad();
	printf("student.name = %s\nstudent.age = %d\n", student.name, student.age);
	return 0;

}
