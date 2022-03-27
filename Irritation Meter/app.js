const http = require('http');

const hostname = '127.0.0.1';
const port = 3000;

const server = http.createServer((req, res) => {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');
  res.end('Hello World');
});

server.listen(port, hostname, () => {
  console.log(`Server running at http://${hostname}:${port}/`);
});




// Javascript program to keep track of maximum
// element in a stack

// main stack
let mainStack = [];

// stack to keep track of max element
let trackStack = [];

function push(x) {
    mainStack.push(x);
    if (mainStack.length == 1)
    {
        trackStack.push(x);
        return;
    }

    // If current element is greater than
    // the top element of track stack, push
    // the current element to track stack
    // otherwise push the element at top of
    // track stack again into it.
    if (x > trackStack[trackStack.length - 1])
        trackStack.push(x);
    else
        trackStack.push(trackStack[trackStack.length - 1]);
}

function getMax() {
    return trackStack[trackStack.length - 1];
}

function pop() {
    mainStack.pop();
    trackStack.pop();
}

push(20);
document.write(getMax() + "</br>");
push(10);
document.write(getMax() + "</br>");
push(50);
document.write(getMax());

// This code is contributed by rameshtravel07.