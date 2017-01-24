//============================================================================
// Name        : lru.cpp
// Author      : ss
// Version     :
// Copyright   : Your copyright notice
// Description : Least Recently Used
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct QNode{
	QNode *prev, *next;
	int pageNumber;
} QNode;

QNode* newQNode(int pn){
	QNode * qnPtr = (QNode *) malloc(sizeof (QNode));
	if (qnPtr){
		qnPtr->pageNumber = pn;
		qnPtr->prev = qnPtr->next = NULL;
		return qnPtr;
	}
	return NULL;
}

typedef struct Queue{
	int numFilled;
	int maxLen;			// Maximum length of the queue
	QNode *front, *rear;
} Queue;

Queue* createQueue(int queueLength){
	Queue * queue = (Queue *)malloc(sizeof (Queue));
	if (queue){
		queue->numFilled = 0;
		queue->front = queue->rear = NULL;
		queue->maxLen = queueLength;
		return queue;
	}
	return queue;
}

typedef struct Hash{
	int capacity;		// Max number of pages
	QNode ** qnArray; 	// Array of queue nodes
} Hash;


Hash* createHash(int cap){
	Hash* hash = (Hash *) malloc(sizeof(Hash));
	if(hash){
		hash->capacity = cap;
		hash->qnArray = (QNode **) malloc(cap*sizeof(QNode*));
		if (hash->qnArray){
			for(int i = 0; i < cap; i++){
				hash->qnArray[i] = NULL;
			}
			return hash;
		}
		free (hash);
		return NULL;
	}
	return NULL;

}

bool checkQueueFull(Queue * queue){
	return (queue->numFilled == queue->maxLen);
}

bool checkQueueEmpty(Queue* queue){
	return (queue->rear == NULL);
}


void DeQueue(Queue* queue){
	if (checkQueueEmpty(queue)){
		return;
	}
	// Queue with one element
	if(queue->numFilled == 1){
		queue->front = NULL;
	}
	// Remove the node from the rear and update the queue registry
	// by removing the current queue->rear and assign queue->rear's next element
	// to queue rear
	QNode* temp = queue->rear;
	queue->rear = queue->rear->prev;

	if(queue->rear){
		queue->rear->next =  NULL;
	}

	free(temp);
	// Reduce the number of filled elements by 1
	queue->numFilled--;
}

void Enqueue(Queue* queue, Hash* hash, unsigned pn){

	// If queue is full, remove the element at the rear
	if (checkQueueFull(queue)){
		hash->qnArray[queue->rear->pageNumber] = NULL;
		DeQueue( queue );
	}

	QNode* qnode = newQNode(pn);
	qnode->next = queue->front;

	// Add
	if(checkQueueEmpty(queue))
		queue->rear =  queue->front = qnode ;
	else{
		queue->front->prev = qnode;
		queue->front = qnode;
	}
	hash->qnArray[pn] = qnode;
	queue->numFilled++;
}


void getPageFromCache(Queue* queue, Hash* hash, int pn){
	if(queue && hash){

		if (pn > 0 && pn < hash->capacity){
			QNode* reqPage = hash->qnArray[pn];
			if (reqPage == NULL)			// Page fault| Page not present in cache
			{	cout << "Page Fault : Page not found - " << pn << endl;
				Enqueue(queue, hash, pn);	// Fetch page from RAM and enqueue
											// else page is here
			}
			else if(reqPage != queue->front)// Check if the page is not already the most recently used page
			{
				reqPage->prev->next = reqPage->next; 	// Update previous front node of the queue to have the requested page as the next one
				if(reqPage->next){						// If request page was pointing to a next page, make the prev
					reqPage->next->prev = reqPage->prev;//
				}

				// If requested page was towards the end of queue
				if(reqPage == queue->rear){
					queue->rear = reqPage->prev; // update the queue pointers
					queue->rear->next = NULL;	 // Last page in the queue is the last one
				}



				reqPage->next = queue->front;
				reqPage->prev = NULL;

				reqPage->next->prev = reqPage;
				// Update the front of the queue
				queue->front = reqPage;
			}
		}
		else
			return;
	}

}

void printQueue(Queue * queue){
	QNode * node = queue->front;
	while(node){
		cout << node->pageNumber << " ";
		node =  node->next;
	}
	cout << endl;
}

int main() {
	cout << "!!! LRU  !!!" << endl; // prints !!! LRU  !!!

	Queue* queue = createQueue(4);

	// Create 10 pages in RAM, values 0-9
	Hash* hash = createHash(10);

	// Refer the pages
	getPageFromCache(queue, hash, 1);
	getPageFromCache(queue, hash, 2);
	getPageFromCache(queue, hash, 4);
	getPageFromCache(queue, hash, 1);
	getPageFromCache(queue, hash, 6);
	getPageFromCache(queue, hash, 7);
	getPageFromCache(queue, hash, 1);
	getPageFromCache(queue, hash, 3);
	getPageFromCache(queue, hash, 1);

	printQueue(queue);
	return 0;
}
