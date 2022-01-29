s = "abcabcbb"
    //Sliding Window 
var lengthOfLongestSubstring = function(s) {
    var strIdx = 0;
    var maxLength = 0;
    var endIdx = 0;
    var sets = new Set();
    for (endIdx = 0; endIdx < s.length; endIdx++) {
        if (sets.has(s[endIdx])) {
            var preEndIdx = Math.max(endIdx - 1, 0);
            maxLength = Math.max(preEndIdx - strIdx + 1, maxLength);
            while (s[strIdx] !== s[endIdx]) {
                sets.delete(s[strIdx++]);
            }
            strIdx++;
        } else {
            sets.add(s[endIdx]);
        }
        if (endIdx === (s.length - 1)) {
            maxLength = Math.max(endIdx - strIdx + 1, maxLength);
        }
    }
    return maxLength;
}

console.log(lengthOfLongestSubstring(s));