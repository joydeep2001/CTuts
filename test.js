function print(message) {
	console.log(message);
}
try {
	let a = 7, b = 7;
	if(a == b) throw "This is an error";
	else print("success"); 
} catch(e) {
	console.error(e);
}