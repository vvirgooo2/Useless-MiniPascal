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
  %gt_cmp = icmp sgt i32 %1, %2
  br i1 %gt_cmp, label %next, label %forbody

forbody:                                          ; preds = %forend, %forentry
  %3 = load i32, i32* @k
  %4 = sub i32 %3, 1
  %5 = getelementptr inbounds [10002 x i32], [10002 x i32]* @a, i32 0, i32 %4
  %6 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.1, i32 0, i32 0), i32* %5)
  br label %forend

forend:                                           ; preds = %forbody
  %7 = load i32, i32* @k
  %add = add i32 %7, 1
  store i32 %add, i32* @k
  %8 = load i32, i32* @k
  %9 = load i32, i32* @n
  %gt_cmp1 = icmp sgt i32 %8, %9
  br i1 %gt_cmp1, label %next, label %forbody

next:                                             ; preds = %forend, %forentry
  %10 = load i32, i32* @n
  %11 = call i32 @qsort(i32 1, i32 %10)
  br label %forentry2

forentry2:                                        ; preds = %next
  store i32 1, i32* @k
  %12 = load i32, i32* @k
  %13 = load i32, i32* @n
  %gt_cmp6 = icmp sgt i32 %12, %13
  br i1 %gt_cmp6, label %next5, label %forbody3

forbody3:                                         ; preds = %forend4, %forentry2
  %14 = load i32, i32* @k
  %15 = sub i32 %14, 1
  %16 = getelementptr inbounds [10002 x i32], [10002 x i32]* @a, i32 0, i32 %15
  %17 = load i32, i32* %16
  %18 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_tempstr.2, i32 0, i32 0), i32 %17)
  br label %forend4

forend4:                                          ; preds = %forbody3
  %19 = load i32, i32* @k
  %add7 = add i32 %19, 1
  store i32 %add7, i32* @k
  %20 = load i32, i32* @k
  %21 = load i32, i32* @n
  %gt_cmp8 = icmp sgt i32 %20, %21
  br i1 %gt_cmp8, label %next5, label %forbody3

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
  %4 = sub i32 %div, 1
  %5 = getelementptr inbounds [10002 x i32], [10002 x i32]* @a, i32 0, i32 %4
  %6 = load i32, i32* %5
  store i32 %6, i32* @m
  br label %repeatbody

repeatbody:                                       ; preds = %end, %entry
  br label %whileentry

end:                                              ; preds = %next9
  %7 = load i32, i32* @i
  %8 = load i32, i32* @j
  %gt_cmp12 = icmp sgt i32 %7, %8
  br i1 %gt_cmp12, label %next, label %repeatbody

next:                                             ; preds = %end
  %9 = load i32, i32* %l
  %10 = load i32, i32* @j
  %lt_cmp13 = icmp slt i32 %9, %10
  br i1 %lt_cmp13, label %then14, label %else15

whileentry:                                       ; preds = %whilebody, %repeatbody
  %11 = load i32, i32* @i
  %12 = sub i32 %11, 1
  %13 = getelementptr inbounds [10002 x i32], [10002 x i32]* @a, i32 0, i32 %12
  %14 = load i32, i32* %13
  %15 = load i32, i32* @m
  %lt_cmp = icmp slt i32 %14, %15
  br i1 %lt_cmp, label %whilebody, label %next3

whilebody:                                        ; preds = %whileentry
  %16 = load i32, i32* @i
  %add4 = add i32 %16, 1
  store i32 %add4, i32* @i
  br label %whileentry

next3:                                            ; preds = %whileentry
  br label %whileentry5

whileentry5:                                      ; preds = %whilebody6, %next3
  %17 = load i32, i32* @j
  %18 = sub i32 %17, 1
  %19 = getelementptr inbounds [10002 x i32], [10002 x i32]* @a, i32 0, i32 %18
  %20 = load i32, i32* %19
  %21 = load i32, i32* @m
  %gt_cmp = icmp sgt i32 %20, %21
  br i1 %gt_cmp, label %whilebody6, label %next7

whilebody6:                                       ; preds = %whileentry5
  %22 = load i32, i32* @j
  %sub = sub i32 %22, 1
  store i32 %sub, i32* @j
  br label %whileentry5

next7:                                            ; preds = %whileentry5
  %23 = load i32, i32* @i
  %24 = load i32, i32* @j
  %gt_cmp8 = icmp sgt i32 %23, %24
  %25 = xor i1 %gt_cmp8, true
  br i1 %25, label %then, label %else

then:                                             ; preds = %next7
  %26 = load i32, i32* @i
  %27 = sub i32 %26, 1
  %28 = getelementptr inbounds [10002 x i32], [10002 x i32]* @a, i32 0, i32 %27
  %29 = load i32, i32* %28
  store i32 %29, i32* @t
  %30 = load i32, i32* @i
  %31 = sub i32 %30, 1
  %32 = getelementptr inbounds [10002 x i32], [10002 x i32]* @a, i32 0, i32 %31
  %33 = load i32, i32* @j
  %34 = sub i32 %33, 1
  %35 = getelementptr inbounds [10002 x i32], [10002 x i32]* @a, i32 0, i32 %34
  %36 = load i32, i32* %35
  store i32 %36, i32* %32
  %37 = load i32, i32* @j
  %38 = sub i32 %37, 1
  %39 = getelementptr inbounds [10002 x i32], [10002 x i32]* @a, i32 0, i32 %38
  %40 = load i32, i32* @t
  store i32 %40, i32* %39
  %41 = load i32, i32* @i
  %add10 = add i32 %41, 1
  store i32 %add10, i32* @i
  %42 = load i32, i32* @j
  %sub11 = sub i32 %42, 1
  store i32 %sub11, i32* @j
  br label %next9

else:                                             ; preds = %next7
  br label %next9

next9:                                            ; preds = %else, %then
  br label %end

then14:                                           ; preds = %next
  %43 = load i32, i32* %l
  %44 = load i32, i32* @j
  %45 = call i32 @qsort(i32 %43, i32 %44)
  br label %next16

else15:                                           ; preds = %next
  br label %next16

next16:                                           ; preds = %else15, %then14
  %46 = load i32, i32* @i
  %47 = load i32, i32* %r
  %lt_cmp17 = icmp slt i32 %46, %47
  br i1 %lt_cmp17, label %then18, label %else19

then18:                                           ; preds = %next16
  %48 = load i32, i32* @i
  %49 = load i32, i32* %r
  %50 = call i32 @qsort(i32 %48, i32 %49)
  br label %next20

else19:                                           ; preds = %next16
  br label %next20

next20:                                           ; preds = %else19, %then18
  %51 = load i32, i32* %qsort
  ret i32 %51
}
