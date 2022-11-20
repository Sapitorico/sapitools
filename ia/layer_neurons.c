#include "network.h"
/**
 * newLayer - Create a new layer of neurons
 * @numNeurons: number of neurons
 * @numWeights: number of weights neurons
 *
 * Return: new layer
 */
layer *newLayer(int numNeurons, int numWeights)
{
	layer *new_l = NULL;
	int iterator = 0;

	new_l = malloc(sizeof(layer));
	new_l->numNeurons = numNeurons;
	new_l->neurons = malloc(sizeof(neuron) * numNeurons);
	for (; iterator < numNeurons; iterator++)
		new_l->neurons[iterator] = *newNeuron(numWeights);
	return (new_l);
}
