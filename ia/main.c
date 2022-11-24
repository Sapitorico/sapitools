#include "network.h"
/**
 */
int main(int argc, char *argv[])
{
	neuralNet *nn;
	double inputs[4] = {1, 1, 1, 1.0};
	double outputs[5];

	/* Initialize random number generator */
	srand(time(NULL));

	/* Create a new neural network */
	nn = newNeuralNet(3, (int []) {2, 1, 2});

	/* Propagate inputs through the neural network */
	propagate(nn, inputs);

	/* Get the outputs of the neural network */
	getOutputs(nn, outputs);

	/* Print the outputs */
	printf("%f\n", outputs[3]);

	/* Free all memory used by the neural network */
	freeNeuralNet(nn);

	return(0);
}
