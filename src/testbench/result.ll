; ModuleID = 'main'
source_filename = "main"

@a = global i32 0
@b = global i32 0
@c = private global [7 x i32] zeroinitializer
@.str = private global [3 x i8] c"%d\00"
@.str.1 = private global [3 x i8] c"%d\00"

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  store i32 190, i32* @a
  br label %forentry

forentry:                                         ; preds = %entry
  store i32 1, i32* @a
  br label %forbody

forbody:                                          ; preds = %forend, %forentry
  %0 = load i32, i32* @a
  %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.1, i32 0, i32 0), i32 %0)
  br label %forend

forend:                                           ; preds = %forbody
  %2 = load i32, i32* @a
  %add = add i32 %2, 1
  store i32 %add, i32* @a
  %3 = load i32, i32* @a
  %gt_cmp = icmp sgt i32 %3, 100
  br i1 %gt_cmp, label %next, label %forbody

next:                                             ; preds = %forend
  ret i32 0
}

define i32 @Testout(i32 %in1) {
entry:
  %in = alloca i32
  store i32 %in1, i32* %in
  %Testout = alloca i32
  store i32 0, i32* %Testout
  %0 = load i32, i32* %in
  %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i32 %0)
  %2 = load i32, i32* %Testout
  ret i32 %2
}
