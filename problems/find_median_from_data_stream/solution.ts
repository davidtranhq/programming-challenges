class MedianFinder {
    arr: number[];
    constructor() {
        this.arr = [];
    }

    addNum(num: number): void {
        let i = 0;
        while (this.arr[i] < num) ++i;
        this.arr.splice(i, 0, num);
    }

    findMedian(): number {
        const len = this.arr.length;
        const mid = Math.ceil(len / 2);
        if (len % 2 == 0) {
            return (this.arr[mid] + this.arr[mid - 1]) / 2;
        } else {
            return this.arr[mid - 1];
        }
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * var obj = new MedianFinder()
 * obj.addNum(num)
 * var param_2 = obj.findMedian()
 */