#include "network.h"
/**
 * newNeuralNet - Create a new neural network
 * @numLayers: number of layers
 * @layerSizes: layer sizes
 *
 * Return: new neural network
 */
neuralNet *newNeuralNet(int numLayers, int *layerSizes)
{
	neuralNet *new = NULL;
	int iterator = 0;
	int numWeights = 0;

	new = malloc(sizeof(neuralNet));
	new->numLayers = numLayers;
	new->layers = malloc(sizeof(layer) * numLayers);
	for (; iterator < numLayers; iterator++)
	{
		numWeights = iterator == 0 ? 0 : layerSizes[iterator - 1];
		new->layers[iterator] = *newLayer(layerSizes[iterator], numWeights);
	}
	return (new);
}
