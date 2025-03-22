"use strict";

const inputs = require("fs")
  .readFileSync("/dev/stdin", "utf8")
  .trim()
  .split("\n");

const [h, w] = inputs[0].split(" ").map(Number);
let s = Object.freeze(
  inputs.slice(1, h + 1).map((v) => Object.freeze(Array.from(v)))
);

const DIRS = Object.freeze([
  Object.freeze([0, +1]),
  Object.freeze([+1, 0]),
  Object.freeze([0, -1]),
  Object.freeze([-1, 0]),
]);

const hasVisited = Array.from({ length: h }, () =>
  Array.from({ length: w }, () => false)
);

function dfs(i, j) {
  if (i < 0 || i >= h || j < 0 || j >= w) return;
  if (hasVisited[i][j]) return;
  if (s[i][j] === "#") return;

  hasVisited[i][j] = true;

  for (const [di, dj] of DIRS) {
    let ci = i;
    let cj = j;
    while (s[ci + di][cj + dj] !== "#") {
      hasVisited[ci][cj] = true;
      ci += di;
      cj += dj;
    }
    dfs(ci, cj);
  }
}

dfs(1, 1);

let ans = 0;
hasVisited.map((row) => row.map((isSatisfied) => (ans += isSatisfied ? 1 : 0)));

console.log(ans);
