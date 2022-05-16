; ModuleID = 'main'
source_filename = "main"

@a = global i32 0
@b = global i32 0
@c = global i32 0
@.str = private global [4 x i8] c"%d\0A\00"

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  store i32 1, i32* @c
  br label %forentry

forentry:                                         ; preds = %entry
  store i32 1, i32* @a
  br label %forbody

forbody:                                          ; preds = %forend, %forentry
  %0 = load i32, i32* @a
  %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i32 %0)
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
