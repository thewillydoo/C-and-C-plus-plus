
#include <stdio.h>
#include <locale.h>

#define ERR -1

#define FROM_SIZE 3
#define TO_SIZE 4

int main()
{
    FILE *fkey;
    FILE *fin;
    FILE *fout;

    setlocale(LC_ALL, "en_US.UTF-8");

    // Set the file paths for the input files
    char fkey_path[] = "C:\\Users\\William\\Desktop\\ECE 220\\Labs\\Lab 2\\Key.dat"; // Change this to your own file path
    char fin_path[] = "C:\\Users\\William\\Desktop\\ECE 220\\Labs\\Lab 2\\Raw.dat"; // Change this to your own file path
    char fout_path[] = "C:\\Users\\William\\Desktop\\ECE 220\\Labs\\Lab 2\\Encoded_result.dat"; // Change this to your own file path

    // Set up the input and output buffers
    unsigned char buf_in[FROM_SIZE];
    unsigned char buf_out[TO_SIZE];

    // Set up the key array for base64 encoding
    char keys[64];

    int count;
    int total_char;

    // Open the key file and load it into the keys array
    fkey = fopen(fkey_path, "r");
    if (fkey == NULL)
    {
        printf("Error: Key file cannot be found");
        return ERR;
    }
    for (int i = 0; i < 64; i++)
    {
        keys[i] = fgetc(fkey);
    }
    fclose(fkey);

    // Open the input file for reading
    fin = fopen(fin_path, "r");
    if (fin == NULL)
    {
        printf("Error: Raw file cannot be found");
        return ERR;
    }

    // Open the output file for writing
    fout = fopen(fout_path, "w");
    if (fout == NULL)
    {
        printf("Error: Encoded file cannot be found");
        return ERR;
    }

    // Initialize the character count
    total_char = 0;

    // Read in 3 bytes at a time from the input file and encode them using base64
    while ((count = fread(buf_in, 1, FROM_SIZE, fin)) == FROM_SIZE)
    {
        // Encode the first 6 bits of the first input byte
        buf_out[0] = keys[(buf_in[0] & (0xFC)) >> 2];

        // Encode the last 2 bits of the first input byte and the first 4 bits of the second input byte
        buf_out[1] = keys[((buf_in[0] & (0x03)) << 4) | ((buf_in[1] & (0xF0)) >> 4)];

        // Encode the last 4 bits of the second input byte and the first 2 bits of the third input byte
        buf_out[2] = keys[((buf_in[1] & (0x0F)) << 2) | ((buf_in[2] & (0xC0)) >> 6)];

        // Encode the last 6 bits of the third input byte
        buf_out[3] = keys[buf_in[2] & (0x3F)];

        // Write the encoded bytes to the output file
        fwrite(buf_out, 1, TO_SIZE, fout);

        // Update the character count
        total_char += TO_SIZE;
        if (total_char % 48 == 0)
        {

            fprintf(fout, "\n");
        }
        else if (total_char % 8 == 0)
        {

            fprintf(fout, " ");
        }
    }

    // Cover the remaining bytes
    if (count != 0)
    {
        // 0xFC=1111 1100
        buf_out[0] = keys[(buf_in[0] & (0xFC)) >> 2];
        if (count == 1)
        {
            // 0x03=0000 0011
            buf_out[1] = keys[((buf_in[0] & (0x03)) << 4)];
            buf_out[2] = '=';
        }
        else if (count == 2)
        {
            // 0x0F=0000 1111
            buf_out[1] = keys[((buf_in[0] & (0x03)) << 4) | ((buf_in[1] & (0xF0)) >> 4)];
            buf_out[2] = keys[((buf_in[1] & (0x0F)) << 2)];
        }
        buf_out[3] = '=';
        fwrite(buf_out, TO_SIZE, 1, fout);
    }
    fclose(fin);
    fclose(fout);

    return 0;
    }


