; ModuleID = 'main'
source_filename = "main"

@a = global i32 0
@b = global i32 0
@c = global [7 x i32] zeroinitializer
@_tempstr = global [7 x i8] c"%.2lf\0A\00"
@.tempstr = global [4 x i8] c"123\00"
@_tempstr.1 = global [4 x i8] c"%s\0A\00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define i32 @main() {
entry:
  store i32 190, i32* @a
  br label %forentry

forentry:                                         ; preds = %entry
  store i32 1, i32* @a
  br label %forbody

forbody:                                          ; preds = %forend, %forentry
  %0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_tempstr.1, i32 0, i32 0), i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.tempstr, i32 0, i32 0))
  br label %forend

forend:                                           ; preds = %forbody
  %1 = load i32, i32* @a
  %add = add i32 %1, 1
  store i32 %add, i32* @a
  %2 = load i32, i32* @a
  %gt_cmp = icmp sgt i32 %2, 100
  br i1 %gt_cmp, label %next, label %forbody

next:                                             ; preds = %forend
  ret i32 0
}

define double @Testout(double %in1) {
entry:
  %in = alloca double
  store double %in1, double* %in
  %Testout = alloca double
  store double 0.000000e+00, double* %Testout
  %0 = load double, double* %in
  %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @_tempstr, i32 0, i32 0), double %0)
  %2 = load double, double* %Testout
  ret double %2
}
