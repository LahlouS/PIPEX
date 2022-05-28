#include <stdio.h>

// int main( int argc, // Number of strings in array argv
// char *argv[],      // Array of command-line argument strings
// char **envp )      // Array of environment variable strings
// {
//     int count;

//     // Display each command-line argument.
//     printf( "\nCommand-line arguments:\n" );
//     for( count = 0; count < argc; count++ )
//         printf( "  argv[%d]   %s\n", count, argv[count] );

//     // Display each environment variable.
//     printf( "\nEnvironment variables:\n" );
//     while( *envp != NULL )
//         printf( "  %s\n", *(envp++) );
//     printf( "  %s\n", *(envp) );

    
//     return 0;
// }

int main( int argc, char *argv[])
{
    // Display each command-line argument.
    printf("*(argv + 1) = %s\n*(argv + (argc - 1)) = %s\n", *(argv + 1), *(argv + (argc - 1)));
    return 0;
}