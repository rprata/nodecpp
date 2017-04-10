var hello = require ('./build/Release/hello.node');
var obj = new hello.MyObject(0);

console.log(obj.plusOne());
console.log(obj.plusOne());
console.log(obj.plusOne());
console.log(obj.plusOne());
console.log(obj.add(10, 20));
console.log(obj.printName(1));

function callback(err) {
	console.log("I woke up after 5s");
	console.log(err.message);
};
obj.wakeup(callback, 5000);
console.log("Finish");