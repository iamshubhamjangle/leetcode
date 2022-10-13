// Return_most_frequent.js
// find the most repeating element and also return its count

const arr = [1,1,2,1,3,5];
const map = {};	// { element: count }

for(let i=0; i<arr.length; i++) {
  map[arr[i]] = (map[arr[i]] || 0) + 1;
}

console.log(map);

let maxNum = 0, maxCount = 0;
for(let key in map) {
	if(map[key] > maxCount) {
  	maxNum = key;
    maxCount = map[key];
  }
}

console.log(maxNum + ' = ' + maxCount);