def encode(src):
    result = ""
    i = 0
    while i < len(src):
        ch = src[i]
        result += ch
        i += 1
        cnt = 1
        while i < len(src) and src[i] == ch:
            cnt += 1
            i += 1
        result += str(cnt)
    return result
