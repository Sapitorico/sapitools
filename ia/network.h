#ifndef NETWORK_H
#define NETWORK_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
/* Data structure for a neuron */
typedef struct neuron
{
	double value;
	double *weights;
	int numWeights;
} neuron;

/* Data structure for a neural network layer */
typedef struct layer
{
	neuron *neurons;
	int numNeurons;
} layer;

/* Data structure for a neural network */
typedef struct neuralNet
{
	layer *layers;
	int numLayers;
} neuralNet;

/* prototypes */
/* Create a new neuron with random weights */
neuron *newNeuron(int numWeights);

/* Create a new layer of neurons */
layer *newLayer(int numNeurons, int numWeights);

/* Create a new neural network */
neuralNet *newNeuralNet(int numLayers, int *layerSizes);

/* Propagate values through the neural network */
void propagate(neuralNet *nn, double *inputs);

/* Get the output values of the neural network */
void getOutputs(neuralNet *nn, double *outputs);

/* Free all memory used by the neural network */
void freeNeuralNet(neuralNet *nn);

#endif
