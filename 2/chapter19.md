# Chapter 19

### Q1

```c++
void *operator new(size_t size) {
    if (void *mem = malloc(size)) {
        return mem;
    }
    else {
        throw std::bad_alloc();
    }
}
void operator delete(void *mem) noexcept { free(mem); }
```

### Q2

```c++

```

### Q3

```c++

```

### Q4

```c++

```

### Q5

```c++

```

### Q6

```c++

```

### Q7

```c++

```

### Q8

```c++

```

### Q9

```c++

```

### Q10

```c++

```

### Q11

```c++

```

### Q12

```c++

```

### Q13

```c++

```

### Q14

```c++

```

### Q15

```c++

```

### Q16

```c++

```

### Q17

```c++

```

### Q18

```c++

```

### Q19

```c++

```

### Q20

```c++

```

### Q21

```c++

```

### Q22

```c++

```

### Q23

```c++

```

### Q24

```c++

```

### Q25

```c++

```

### Q26

```c++

```