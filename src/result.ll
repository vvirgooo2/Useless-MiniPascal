; ModuleID = 'main'
source_filename = "main"

@n = global i32 0
@k = global i32 0
@a = global [10002 x i32] zeroinitializer
@i = global i32 0
@j = global i32 0
@m = global i32 0
@t = global i32 0
@_tempstr = global [3 x i8] c"%d\00"
@_tempstr.1 = global [3 x i8] c"%d\00"
@_tempstr.2 = global [4 x i8] c"%d\0A\00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define i32 @main() {
entry:
  %0 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr, i32 0, i32 0), i32* @n)
  br label %forentry

forentry:                                         ; preds = %entry
  store i32 1, i32* @k
  %1 = load i32, i32* @k
  %2 = load i32, i32* @n
  %gt = icmp sgt i32 %1, %2
  br i1 %gt, label %next, label %forbody

forbody:                                          ; preds = %forend, %forentry
  %3 = load i32, i32* @k
  %sub = sub i32 %3, 1
  %4 = getelementptr inbounds [10002 x i32], [10002 x i32]* @a, i32 0, i32 %sub
  %5 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.1, i32 0, i32 0), i32* %4)
  br label %forend

forend:                                           ; preds = %forbody
  %6 = load i32, i32* @k
  %add = add i32 %6, 1
  store i32 %add, i32* @k
  %7 = load i32, i32* @k
  %8 = load i32, i32* @n
  %gt1 = icmp sgt i32 %7, %8
  br i1 %gt1, label %next, label %forbody

next:                                             ; preds = %forend, %forentry
  %9 = load i32, i32* @n
  %10 = call i32 @qsort(i32 1, i32 %9)
  br label %forentry2

forentry2:                                        ; preds = %next
  store i32 1, i32* @k
  %11 = load i32, i32* @k
  %12 = load i32, i32* @n
  %gt6 = icmp sgt i32 %11, %12
  br i1 %gt6, label %next5, label %forbody3

forbody3:                                         ; preds = %forend4, %forentry2
  %13 = load i32, i32* @k
  %sub7 = sub i32 %13, 1
  %14 = getelementptr inbounds [10002 x i32], [10002 x i32]* @a, i32 0, i32 %sub7
  %15 = load i32, i32* %14
  %16 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_tempstr.2, i32 0, i32 0), i32 %15)
  br label %forend4

forend4:                                          ; preds = %forbody3
  %17 = load i32, i32* @k
  %add8 = add i32 %17, 1
  store i32 %add8, i32* @k
  %18 = load i32, i32* @k
  %19 = load i32, i32* @n
  %gt9 = icmp sgt i32 %18, %19
  br i1 %gt9, label %next5, label %forbody3

next5:                                            ; preds = %forend4, %forentry2
  ret i32 0
}

define i32 @qsort(i32 %l1, i32 %r2) {
entry:
  %l = alloca i32
  %r = alloca i32
  store i32 %l1, i32* %l
  store i32 %r2, i32* %r
  %qsort = alloca i32
  store i32 0, i32* %qsort
  %0 = load i32, i32* %l
  store i32 %0, i32* @i
  %1 = load i32, i32* %r
  store i32 %1, i32* @j
  %2 = load i32, i32* %l
  %3 = load i32, i32* %r
  %add = add i32 %2, %3
  %div = sdiv i32 %add, 2
  %sub = sub i32 %div, 1
  %4 = getelementptr inbounds [10002 x i32], [10002 x i32]* @a, i32 0, i32 %sub
  %5 = load i32, i32* %4
  store i32 %5, i32* @m
  br label %repeatbody

repeatbody:                                       ; preds = %end, %entry
  br label %whileentry

end:                                              ; preds = %next12
  %6 = load i32, i32* @i
  %7 = load i32, i32* @j
  %gt19 = icmp sgt i32 %6, %7
  br i1 %gt19, label %next, label %repeatbody

next:                                             ; preds = %end
  %8 = load i32, i32* %l
  %9 = load i32, i32* @j
  %lt20 = icmp slt i32 %8, %9
  br i1 %lt20, label %then21, label %else22

whileentry:                                       ; preds = %whilebody, %repeatbody
  %10 = load i32, i32* @i
  %sub4 = sub i32 %10, 1
  %11 = getelementptr inbounds [10002 x i32], [10002 x i32]* @a, i32 0, i32 %sub4
  %12 = load i32, i32* %11
  %13 = load i32, i32* @m
  %lt = icmp slt i32 %12, %13
  br i1 %lt, label %whilebody, label %next3

whilebody:                                        ; preds = %whileentry
  %14 = load i32, i32* @i
  %add5 = add i32 %14, 1
  store i32 %add5, i32* @i
  br label %whileentry

next3:                                            ; preds = %whileentry
  br label %whileentry6

whileentry6:                                      ; preds = %whilebody7, %next3
  %15 = load i32, i32* @j
  %sub9 = sub i32 %15, 1
  %16 = getelementptr inbounds [10002 x i32], [10002 x i32]* @a, i32 0, i32 %sub9
  %17 = load i32, i32* %16
  %18 = load i32, i32* @m
  %gt = icmp sgt i32 %17, %18
  br i1 %gt, label %whilebody7, label %next8

whilebody7:                                       ; preds = %whileentry6
  %19 = load i32, i32* @j
  %sub10 = sub i32 %19, 1
  store i32 %sub10, i32* @j
  br label %whileentry6

next8:                                            ; preds = %whileentry6
  %20 = load i32, i32* @i
  %21 = load i32, i32* @j
  %gt11 = icmp sgt i32 %20, %21
  %22 = xor i1 %gt11, true
  br i1 %22, label %then, label %else

then:                                             ; preds = %next8
  %23 = load i32, i32* @i
  %sub13 = sub i32 %23, 1
  %24 = getelementptr inbounds [10002 x i32], [10002 x i32]* @a, i32 0, i32 %sub13
  %25 = load i32, i32* %24
  store i32 %25, i32* @t
  %26 = load i32, i32* @i
  %sub14 = sub i32 %26, 1
  %27 = getelementptr inbounds [10002 x i32], [10002 x i32]* @a, i32 0, i32 %sub14
  %28 = load i32, i32* @j
  %sub15 = sub i32 %28, 1
  %29 = getelementptr inbounds [10002 x i32], [10002 x i32]* @a, i32 0, i32 %sub15
  %30 = load i32, i32* %29
  store i32 %30, i32* %27
  %31 = load i32, i32* @j
  %sub16 = sub i32 %31, 1
  %32 = getelementptr inbounds [10002 x i32], [10002 x i32]* @a, i32 0, i32 %sub16
  %33 = load i32, i32* @t
  store i32 %33, i32* %32
  %34 = load i32, i32* @i
  %add17 = add i32 %34, 1
  store i32 %add17, i32* @i
  %35 = load i32, i32* @j
  %sub18 = sub i32 %35, 1
  store i32 %sub18, i32* @j
  br label %next12

else:                                             ; preds = %next8
  br label %next12

next12:                                           ; preds = %else, %then
  br label %end

then21:                                           ; preds = %next
  %36 = load i32, i32* %l
  %37 = load i32, i32* @j
  %38 = call i32 @qsort(i32 %36, i32 %37)
  br label %next23

else22:                                           ; preds = %next
  br label %next23

next23:                                           ; preds = %else22, %then21
  %39 = load i32, i32* @i
  %40 = load i32, i32* %r
  %lt24 = icmp slt i32 %39, %40
  br i1 %lt24, label %then25, label %else26

then25:                                           ; preds = %next23
  %41 = load i32, i32* @i
  %42 = load i32, i32* %r
  %43 = call i32 @qsort(i32 %41, i32 %42)
  br label %next27

else26:                                           ; preds = %next23
  br label %next27

next27:                                           ; preds = %else26, %then25
  %44 = load i32, i32* %qsort
  ret i32 %44
}
