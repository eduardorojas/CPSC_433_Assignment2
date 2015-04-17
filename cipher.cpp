#include <string>
#include <iostream>
#include "CipherInterface.h"
#include "DES.h"
#include "RSA.h"

using namespace std;

int main(int argc, char** argv)
{
	/* REPLACE THIS PART WITH YOUR CODE 
	 * THE CODE BELOW IS A SAMPLE TO 
	 * ILLUSTRATE INSTANTIATION OF CLASSES
	 * THAT USE THE SAME INTERFACE.
	 */	
		

	/* Create an instance of the DES cipher */	
	CipherInterface* cipher = new DES();
	
	/* Error checks */
	if(!cipher)
	{
		fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
		__FILE__, __FUNCTION__, __LINE__);
		exit(-1);
	}
	
	/* Set the encryption key
	 * A valid key comprises 16 hexidecimal
	 * characters. Below is one example.
	 * Your program should take input from
	 * command line.
	 */
	cipher->setKey((unsigned char*)"0123456789abcdef");
	/* Perform encryption */
	unsigned char * ciphertext = cipher->encrypt((const unsigned char*)"hellohel");
	
	/* Perform decryption */
	unsigned char * plain = cipher->decrypt(ciphertext);
	printf("DES Decryption: %s\n", plain);	
	

	//RSA 
	CipherInterface *rsatest = new RSA_433();
	const unsigned char pubfile[] = "pubkey.pem";
	
	rsatest->setKey(pubfile);
	cout << endl;
	unsigned char * RSA_ciphertext = rsatest->encrypt((const unsigned char*)"hello");
	cout << "RSA Encryption: \n" << RSA_ciphertext << endl;

	const unsigned char privfile[] = "privkey.pem";
	rsatest->setKey(privfile);

	unsigned char * RSA_plaintext = rsatest->decrypt(RSA_ciphertext);
	cout << "RSA Decryption: \n" << RSA_plaintext;
	return 0;
}
