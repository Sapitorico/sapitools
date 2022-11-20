#include "network.h"
/**
 * newNeuron - Create a new neuron with random weights
 * @numWeights: weights
 *
 * Return: new neuron with random weights
 */
neuron *newNeuron(int numWeights)
{
	neuron *new_w = NULL;
	int iterator = 0;

	new_w = malloc(sizeof(neuron));
	new_w->numWeights = numWeights;
	new_w->weights = malloc(sizeof(double) * numWeights);
	for (; iterator < numWeights; iterator++)
		new_w->weights[iterator] = ((double)rand() / (double)RAND_MAX) * 2 - 1;
	return (new_w);
}
