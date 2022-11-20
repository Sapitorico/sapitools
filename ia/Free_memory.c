#include "network.h"
/**
 */
void freeNeuralNet(neuralNet *nn)
{
	int i = 0;
	int j = 0;
	layer *l = NULL;
	neuron *n = NULL;

	for (; i < nn->numLayers; i++)
	{
		l = &nn->layers[i];
		for (; j < l->numNeurons; j++)
		{
			n = &l->neurons[j];
			free(n->weights);
		}
		free(l->neurons);
	}
	free(nn->layers);
	free(nn);
}
