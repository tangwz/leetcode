func twoSum(nums []int, target int) []int {
	d := make(map[int]int)
	for i, v := range nums {
		if val, ok := d[v]; ok {
			return []int{val, i}
		} else {
			d[target - v] = i
		}
	}
	return []int{}
}
