let nums = [2, 7, 11, 15];
let target = 9;

/*
var twoSum = function(nums, target) {
    for (let x = 0; x < nums.length; x++) {
        let goal = target - nums[x];
        for (let y = x + 1; y <= nums.length; y++) {
            if (nums[y] === goal)
                return [x, y];
        }
    }
}
*/
var twoSum = function(nums, target) {
    var map = {};
    for (let i = 0; i < nums.length; i++) {
        if (map[target - nums[i]] >= 0) {
            return [map[target - nums[i]], i];
        } else {
            map[nums[i]] = i;
        }
    }
}

console.log(twoSum(nums, target));