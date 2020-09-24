def solution(data, occuranceLimit):
    singles=set()

    if occuranceLimit == 0:
        return singles

    buckets = []
    isDeleted = []
    for i in xrange(0,101):
        buckets.append(0)
    for i in xrange(0,101):
        isDeleted.append(False)

    for d in data:
        if buckets[d] < occuranceLimit:
            singles.add(d)
        elif buckets[d] >= occuranceLimit and isDeleted[d] is False:
            isDeleted[d]=True
            singles.remove(d)

        buckets[d]=buckets[d]+1

    print singles


solution([1, 2, 2, 2, 5], 3)
