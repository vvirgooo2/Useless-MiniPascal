; ModuleID = 'main'
source_filename = "main"

@a = global i32 0
@b = global i32 0
@c = global i32 0

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  store i32 1, i32* @c
  br label %forentry

forentry:                                         ; preds = %entry
  store i32 1, i32* @a
  br label %forbody

forbody:                                          ; preds = %forend, %forentry
  br label %forend

forend:                                           ; preds = %forbody
  %0 = load i32, i32* @a
  %add = add i32 %0, 1
  store i32 %add, i32* @a
  %1 = load i32, i32* @a
  %gt_cmp = icmp sgt i32 %1, 100
  br i1 %gt_cmp, label %next, label %forbody

next:                                             ; preds = %forend
  ret i32 0
}
