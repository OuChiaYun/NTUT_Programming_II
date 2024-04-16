isEmpty():head == tail
if full():


bool isEmpty(int front, int back) {
return (front==back);
}
bool isFull(int front, int back) {
return (((back+1)%SIZE)==front);
}