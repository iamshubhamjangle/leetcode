#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << max({1,2,3,4,5}) << endl;
    cout << max(1,2) << endl;
}

function findMissing(a, b, n, m) {
    let missing = [];
    for (let i = 0; i < n; i++) {
        let j;
        for (j = 0; j < m; j++) if (a[i] == b[j]) break;
        if (j == m) missing.push(a[i]); // following was not present in follower
    }
    return missing;
}

const followersNames = [];
for(let e of document.getElementsByClassName("_ab8y  _ab94 _ab97 _ab9f _ab9k _ab9p _abcm")) followersNames.push(e.innerText);

const followingNames = [];
for(let e of document.getElementsByClassName("_ab8y  _ab94 _ab97 _ab9f _ab9k _ab9p _abcm")) followingNames.push(e.innerText);

console.log(findMissing(followingNames, followersNames, followingNames.length, followersNames.length));
console.log(findMissing(followersNames, followingNames, followersNames.length, followingNames.length));





// Step 1: Open instagram on laptop/desktop
// Step 2: Open devtool using ctrl + shift + i
// Step 3: Open followers list, load complete list and paste this
function findMissing(l,o,s,a){let n=[];for(let f=0;f<s;f++){let t;for(t=0;t<a&&l[f]!=o[t];t++);t==a&&n.push(l[f])}return n}const followersNames=[];for(let e of document.getElementsByClassName("_ab8y  _ab94 _ab97 _ab9f _ab9k _ab9p _abcm"))followersNames.push(e.innerText);
// Step 4: Open following list, load complete list and paste this
const followingNames=[];for(let e of document.getElementsByClassName("_ab8y  _ab94 _ab97 _ab9f _ab9k _ab9p _abcm"))followingNames.push(e.innerText);console.log('People who dont follow you back',findMissing(followingNames,followersNames,followingNames.length,followersNames.length)),console.log('People who follow you, but you dont follow back',findMissing(followersNames,followingNames,followersNames.length,followingNames.length));