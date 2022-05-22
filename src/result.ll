; ModuleID = 'main'
source_filename = "main"

@count = global i32 0
@cname = global [10000 x i8] zeroinitializer
@credits = global [1000 x i32] zeroinitializer
@conditions = global [10000000 x i8] zeroinitializer
@score = global [1000 x i32] zeroinitializer
@i = global i32 0
@j = global i32 0
@k = global i32 0
@l = global i32 0
@num = global i32 0
@t = global i32 0
@ch = global i8 0
@orcount = global i32 0
@andcount = global i32 0
@len = global i32 0
@attempt = global i32 0
@attemptF = global double 0.000000e+00
@complete = global i32 0
@total = global i32 0
@totalF = global double 0.000000e+00
@need = global i32 0
@GPA = global double 0.000000e+00
@count2 = global i32 0
@flagi = global i32 0
@flagj = global i32 0
@flagk = global i32 0
@namec = global i32 0
@funci = global i32 0
@_tempstr = global [3 x i8] c"%c\00"
@_tempstr.1 = global [3 x i8] c"%c\00"
@_tempstr.2 = global [3 x i8] c"%c\00"
@_tempstr.3 = global [3 x i8] c"%c\00"
@_tempstr.4 = global [3 x i8] c"%d\00"
@_tempstr.5 = global [3 x i8] c"%c\00"
@_tempstr.6 = global [3 x i8] c"%c\00"
@_tempstr.7 = global [3 x i8] c"%c\00"
@_tempstr.8 = global [3 x i8] c"%c\00"
@_tempstr.9 = global [3 x i8] c"%c\00"
@.tempstr = global [6 x i8] c"GPA: \00"
@_tempstr.10 = global [9 x i8] c"%s%.1lf\0A\00"
@.tempstr.11 = global [18 x i8] c"Hours Attempted: \00"
@_tempstr.12 = global [6 x i8] c"%s%d\0A\00"
@.tempstr.13 = global [18 x i8] c"Hours Completed: \00"
@_tempstr.14 = global [6 x i8] c"%s%d\0A\00"
@.tempstr.15 = global [20 x i8] c"Credits Remaining: \00"
@_tempstr.16 = global [6 x i8] c"%s%d\0A\00"
@.tempstr.17 = global [1 x i8] zeroinitializer
@_tempstr.18 = global [4 x i8] c"%s\0A\00"
@.tempstr.19 = global [25 x i8] c"Possible Courses to Take\00"
@_tempstr.20 = global [3 x i8] c"%s\00"
@.tempstr.21 = global [6 x i8] c" Next\00"
@_tempstr.22 = global [4 x i8] c"%s\0A\00"
@.tempstr.23 = global [3 x i8] c"  \00"
@_tempstr.24 = global [3 x i8] c"%s\00"
@.tempstr.25 = global [1 x i8] zeroinitializer
@_tempstr.26 = global [4 x i8] c"%s\0A\00"
@.tempstr.27 = global [25 x i8] c"  None - Congratulations\00"
@_tempstr.28 = global [3 x i8] c"%s\00"
@.tempstr.29 = global [2 x i8] c"!\00"
@_tempstr.30 = global [4 x i8] c"%s\0A\00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define i32 @main() {
entry:
  store i32 1, i32* @count
  br label %whileentry

whileentry:                                       ; preds = %next74, %entry
  br i1 true, label %whilebody, label %next

whilebody:                                        ; preds = %whileentry
  %0 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.2, i32 0, i32 0), i8* @ch)
  %1 = load i8, i8* @ch
  %eq_cmp = icmp eq i8 %1, 10
  %2 = load i8, i8* @ch
  %eq_cmp1 = icmp eq i8 %2, 0
  %or = or i1 %eq_cmp, %eq_cmp1
  br i1 %or, label %then, label %else

next:                                             ; preds = %then, %whileentry
  br label %forentry

then:                                             ; preds = %whilebody
  br label %next

else:                                             ; preds = %whilebody
  br label %next2

next2:                                            ; preds = %else
  store i32 1, i32* @len
  br label %whileentry3

whileentry3:                                      ; preds = %whilebody4, %next2
  %3 = load i8, i8* @ch
  %ne_cmp = icmp ne i8 %3, 124
  br i1 %ne_cmp, label %whilebody4, label %next5

whilebody4:                                       ; preds = %whileentry3
  %4 = load i32, i32* @count
  %mul = mul i32 %4, 10
  %5 = load i32, i32* @len
  %add = add i32 %mul, %5
  %sub = sub i32 %add, 1
  %6 = getelementptr inbounds [10000 x i8], [10000 x i8]* @cname, i32 0, i32 %sub
  %7 = load i8, i8* @ch
  store i8 %7, i8* %6
  %8 = load i32, i32* @len
  %add6 = add i32 %8, 1
  store i32 %add6, i32* @len
  %9 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.3, i32 0, i32 0), i8* @ch)
  br label %whileentry3

next5:                                            ; preds = %whileentry3
  %10 = load i32, i32* @count
  %sub7 = sub i32 %10, 1
  %11 = getelementptr inbounds [1000 x i32], [1000 x i32]* @credits, i32 0, i32 %sub7
  %12 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.4, i32 0, i32 0), i32* %11)
  %13 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.5, i32 0, i32 0), i8* @ch)
  %14 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.6, i32 0, i32 0), i8* @ch)
  %15 = load i8, i8* @ch
  %ne_cmp8 = icmp ne i8 %15, 124
  br i1 %ne_cmp8, label %then9, label %else10

then9:                                            ; preds = %next5
  store i32 1, i32* @orcount
  store i32 1, i32* @andcount
  store i32 1, i32* @namec
  br label %whileentry12

else10:                                           ; preds = %next5
  br label %next11

next11:                                           ; preds = %else10, %next14
  %16 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.8, i32 0, i32 0), i8* @ch)
  %17 = load i8, i8* @ch
  %eq_cmp46 = icmp eq i8 %17, 65
  br i1 %eq_cmp46, label %then47, label %else48

whileentry12:                                     ; preds = %next45, %then9
  br i1 true, label %whilebody13, label %next14

whilebody13:                                      ; preds = %whileentry12
  %18 = load i8, i8* @ch
  %ne_cmp15 = icmp ne i8 %18, 44
  %19 = load i8, i8* @ch
  %ne_cmp16 = icmp ne i8 %19, 59
  %and = and i1 %ne_cmp15, %ne_cmp16
  %20 = load i8, i8* @ch
  %ne_cmp17 = icmp ne i8 %20, 124
  %and18 = and i1 %and, %ne_cmp17
  br i1 %and18, label %then19, label %else20

next14:                                           ; preds = %then43, %whileentry12
  br label %next11

then19:                                           ; preds = %whilebody13
  %21 = load i32, i32* @count
  %mul22 = mul i32 %21, 1000
  %22 = load i32, i32* @orcount
  %mul23 = mul i32 %22, 100
  %add24 = add i32 %mul22, %mul23
  %23 = load i32, i32* @andcount
  %mul25 = mul i32 %23, 10
  %add26 = add i32 %add24, %mul25
  %24 = load i32, i32* @namec
  %add27 = add i32 %add26, %24
  %sub28 = sub i32 %add27, 1
  %25 = getelementptr inbounds [10000000 x i8], [10000000 x i8]* @conditions, i32 0, i32 %sub28
  %26 = load i8, i8* @ch
  store i8 %26, i8* %25
  %27 = load i32, i32* @namec
  %add29 = add i32 %27, 1
  store i32 %add29, i32* @namec
  br label %next21

else20:                                           ; preds = %whilebody13
  br label %next21

next21:                                           ; preds = %else20, %then19
  %28 = load i8, i8* @ch
  %eq_cmp30 = icmp eq i8 %28, 44
  br i1 %eq_cmp30, label %then31, label %else32

then31:                                           ; preds = %next21
  %29 = load i32, i32* @andcount
  %add34 = add i32 %29, 1
  store i32 %add34, i32* @andcount
  store i32 1, i32* @namec
  br label %next33

else32:                                           ; preds = %next21
  br label %next33

next33:                                           ; preds = %else32, %then31
  %30 = load i8, i8* @ch
  %eq_cmp35 = icmp eq i8 %30, 59
  %31 = load i8, i8* @ch
  %eq_cmp36 = icmp eq i8 %31, 124
  %or37 = or i1 %eq_cmp35, %eq_cmp36
  br i1 %or37, label %then38, label %else39

then38:                                           ; preds = %next33
  %32 = load i32, i32* @orcount
  %add41 = add i32 %32, 1
  store i32 %add41, i32* @orcount
  store i32 1, i32* @andcount
  store i32 1, i32* @namec
  br label %next40

else39:                                           ; preds = %next33
  br label %next40

next40:                                           ; preds = %else39, %then38
  %33 = load i8, i8* @ch
  %eq_cmp42 = icmp eq i8 %33, 124
  br i1 %eq_cmp42, label %then43, label %else44

then43:                                           ; preds = %next40
  br label %next14

else44:                                           ; preds = %next40
  br label %next45

next45:                                           ; preds = %else44
  %34 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.7, i32 0, i32 0), i8* @ch)
  br label %whileentry12

then47:                                           ; preds = %next11
  %35 = load i32, i32* @count
  %sub50 = sub i32 %35, 1
  %36 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %sub50
  store i32 4, i32* %36
  br label %next49

else48:                                           ; preds = %next11
  br label %next49

next49:                                           ; preds = %else48, %then47
  %37 = load i8, i8* @ch
  %eq_cmp51 = icmp eq i8 %37, 66
  br i1 %eq_cmp51, label %then52, label %else53

then52:                                           ; preds = %next49
  %38 = load i32, i32* @count
  %sub55 = sub i32 %38, 1
  %39 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %sub55
  store i32 3, i32* %39
  br label %next54

else53:                                           ; preds = %next49
  br label %next54

next54:                                           ; preds = %else53, %then52
  %40 = load i8, i8* @ch
  %eq_cmp56 = icmp eq i8 %40, 67
  br i1 %eq_cmp56, label %then57, label %else58

then57:                                           ; preds = %next54
  %41 = load i32, i32* @count
  %sub60 = sub i32 %41, 1
  %42 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %sub60
  store i32 2, i32* %42
  br label %next59

else58:                                           ; preds = %next54
  br label %next59

next59:                                           ; preds = %else58, %then57
  %43 = load i8, i8* @ch
  %eq_cmp61 = icmp eq i8 %43, 68
  br i1 %eq_cmp61, label %then62, label %else63

then62:                                           ; preds = %next59
  %44 = load i32, i32* @count
  %sub65 = sub i32 %44, 1
  %45 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %sub65
  store i32 1, i32* %45
  br label %next64

else63:                                           ; preds = %next59
  br label %next64

next64:                                           ; preds = %else63, %then62
  %46 = load i8, i8* @ch
  %eq_cmp66 = icmp eq i8 %46, 70
  br i1 %eq_cmp66, label %then67, label %else68

then67:                                           ; preds = %next64
  %47 = load i32, i32* @count
  %sub70 = sub i32 %47, 1
  %48 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %sub70
  store i32 0, i32* %48
  br label %next69

else68:                                           ; preds = %next64
  br label %next69

next69:                                           ; preds = %else68, %then67
  %49 = load i8, i8* @ch
  %eq_cmp71 = icmp eq i8 %49, 10
  br i1 %eq_cmp71, label %then72, label %else73

then72:                                           ; preds = %next69
  %50 = load i32, i32* @count
  %sub75 = sub i32 %50, 1
  %51 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %sub75
  store i32 -1, i32* %51
  br label %next74

else73:                                           ; preds = %next69
  %52 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.9, i32 0, i32 0), i8* @ch)
  br label %next74

next74:                                           ; preds = %else73, %then72
  %53 = load i32, i32* @count
  %add76 = add i32 %53, 1
  store i32 %add76, i32* @count
  br label %whileentry

forentry:                                         ; preds = %next
  store i32 1, i32* @i
  %54 = load i32, i32* @i
  %55 = load i32, i32* @count
  %sub78 = sub i32 %55, 1
  %gt_cmp = icmp sgt i32 %54, %sub78
  br i1 %gt_cmp, label %next77, label %forbody

forbody:                                          ; preds = %forend, %forentry
  %56 = load i32, i32* @i
  %sub79 = sub i32 %56, 1
  %57 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %sub79
  %58 = load i32, i32* %57
  %eq_cmp80 = icmp eq i32 %58, 0
  br i1 %eq_cmp80, label %then81, label %else82

forend:                                           ; preds = %next98
  %59 = load i32, i32* @i
  %add105 = add i32 %59, 1
  store i32 %add105, i32* @i
  %60 = load i32, i32* @i
  %61 = load i32, i32* @count
  %sub106 = sub i32 %61, 1
  %gt_cmp107 = icmp sgt i32 %60, %sub106
  br i1 %gt_cmp107, label %next77, label %forbody

next77:                                           ; preds = %forend, %forentry
  %62 = load i32, i32* @total
  %63 = sitofp i32 %62 to double
  store double %63, double* @totalF
  %64 = load i32, i32* @attempt
  %65 = sitofp i32 %64 to double
  store double %65, double* @attemptF
  %66 = load i32, i32* @attempt
  %gt_cmp108 = icmp sgt i32 %66, 0
  br i1 %gt_cmp108, label %then109, label %else110

then81:                                           ; preds = %forbody
  %67 = load i32, i32* @attempt
  %68 = load i32, i32* @i
  %sub84 = sub i32 %68, 1
  %69 = getelementptr inbounds [1000 x i32], [1000 x i32]* @credits, i32 0, i32 %sub84
  %70 = load i32, i32* %69
  %add85 = add i32 %67, %70
  store i32 %add85, i32* @attempt
  br label %next83

else82:                                           ; preds = %forbody
  br label %next83

next83:                                           ; preds = %else82, %then81
  %71 = load i32, i32* @i
  %sub86 = sub i32 %71, 1
  %72 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %sub86
  %73 = load i32, i32* %72
  %gt_cmp87 = icmp sgt i32 %73, 0
  br i1 %gt_cmp87, label %then88, label %else89

then88:                                           ; preds = %next83
  %74 = load i32, i32* @attempt
  %75 = load i32, i32* @i
  %sub91 = sub i32 %75, 1
  %76 = getelementptr inbounds [1000 x i32], [1000 x i32]* @credits, i32 0, i32 %sub91
  %77 = load i32, i32* %76
  %add92 = add i32 %74, %77
  store i32 %add92, i32* @attempt
  %78 = load i32, i32* @complete
  %79 = load i32, i32* @i
  %sub93 = sub i32 %79, 1
  %80 = getelementptr inbounds [1000 x i32], [1000 x i32]* @credits, i32 0, i32 %sub93
  %81 = load i32, i32* %80
  %add94 = add i32 %78, %81
  store i32 %add94, i32* @complete
  br label %next90

else89:                                           ; preds = %next83
  br label %next90

next90:                                           ; preds = %else89, %then88
  %82 = load i32, i32* @i
  %sub95 = sub i32 %82, 1
  %83 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %sub95
  %84 = load i32, i32* %83
  %ge_cmp = icmp sge i32 %84, 0
  br i1 %ge_cmp, label %then96, label %else97

then96:                                           ; preds = %next90
  %85 = load i32, i32* @total
  %86 = load i32, i32* @i
  %sub99 = sub i32 %86, 1
  %87 = getelementptr inbounds [1000 x i32], [1000 x i32]* @credits, i32 0, i32 %sub99
  %88 = load i32, i32* %87
  %89 = load i32, i32* @i
  %sub100 = sub i32 %89, 1
  %90 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %sub100
  %91 = load i32, i32* %90
  %mul101 = mul i32 %88, %91
  %add102 = add i32 %85, %mul101
  store i32 %add102, i32* @total
  br label %next98

else97:                                           ; preds = %next90
  br label %next98

next98:                                           ; preds = %else97, %then96
  %92 = load i32, i32* @need
  %93 = load i32, i32* @i
  %sub103 = sub i32 %93, 1
  %94 = getelementptr inbounds [1000 x i32], [1000 x i32]* @credits, i32 0, i32 %sub103
  %95 = load i32, i32* %94
  %add104 = add i32 %92, %95
  store i32 %add104, i32* @need
  br label %forend

then109:                                          ; preds = %next77
  %96 = load double, double* @totalF
  %97 = load double, double* @attemptF
  %div = fdiv double %96, %97
  store double %div, double* @GPA
  br label %next111

else110:                                          ; preds = %next77
  br label %next111

next111:                                          ; preds = %else110, %then109
  %98 = load i32, i32* @need
  %99 = load i32, i32* @complete
  %sub112 = sub i32 %98, %99
  store i32 %sub112, i32* @need
  %100 = load double, double* @GPA
  %101 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([9 x i8], [9 x i8]* @_tempstr.10, i32 0, i32 0), i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.tempstr, i32 0, i32 0), double %100)
  %102 = load i32, i32* @attempt
  %103 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @_tempstr.12, i32 0, i32 0), i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.tempstr.11, i32 0, i32 0), i32 %102)
  %104 = load i32, i32* @complete
  %105 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @_tempstr.14, i32 0, i32 0), i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.tempstr.13, i32 0, i32 0), i32 %104)
  %106 = load i32, i32* @need
  %107 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @_tempstr.16, i32 0, i32 0), i8* getelementptr inbounds ([20 x i8], [20 x i8]* @.tempstr.15, i32 0, i32 0), i32 %106)
  %108 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_tempstr.18, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8], [1 x i8]* @.tempstr.17, i32 0, i32 0))
  %109 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.20, i32 0, i32 0), i8* getelementptr inbounds ([25 x i8], [25 x i8]* @.tempstr.19, i32 0, i32 0))
  %110 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_tempstr.22, i32 0, i32 0), i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.tempstr.21, i32 0, i32 0))
  store i32 1, i32* @j
  store i32 1, i32* @k
  br label %forentry113

forentry113:                                      ; preds = %next111
  store i32 1, i32* @i
  %111 = load i32, i32* @i
  %112 = load i32, i32* @count
  %sub117 = sub i32 %112, 1
  %gt_cmp118 = icmp sgt i32 %111, %sub117
  br i1 %gt_cmp118, label %next116, label %forbody114

forbody114:                                       ; preds = %forend115, %forentry113
  store i32 0, i32* @flagi
  %113 = load i32, i32* @i
  %sub119 = sub i32 %113, 1
  %114 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %sub119
  %115 = load i32, i32* %114
  %le_cmp = icmp sle i32 %115, 0
  br i1 %le_cmp, label %then120, label %else121

forend115:                                        ; preds = %next122
  %116 = load i32, i32* @i
  %add187 = add i32 %116, 1
  store i32 %add187, i32* @i
  %117 = load i32, i32* @i
  %118 = load i32, i32* @count
  %sub188 = sub i32 %118, 1
  %gt_cmp189 = icmp sgt i32 %117, %sub188
  br i1 %gt_cmp189, label %next116, label %forbody114

next116:                                          ; preds = %forend115, %forentry113
  %119 = load i32, i32* @need
  %eq_cmp190 = icmp eq i32 %119, 0
  br i1 %eq_cmp190, label %then191, label %else192

then120:                                          ; preds = %forbody114
  store i32 0, i32* @flagi
  %120 = load i32, i32* @i
  %mul123 = mul i32 %120, 1000
  %add124 = add i32 %mul123, 100
  %add125 = add i32 %add124, 10
  %add126 = add i32 %add125, 1
  %sub127 = sub i32 %add126, 1
  %121 = getelementptr inbounds [10000000 x i8], [10000000 x i8]* @conditions, i32 0, i32 %sub127
  %122 = load i8, i8* %121
  %eq_cmp128 = icmp eq i8 %122, 0
  br i1 %eq_cmp128, label %then129, label %else130

else121:                                          ; preds = %forbody114
  br label %next122

next122:                                          ; preds = %else121, %next184
  br label %forend115

then129:                                          ; preds = %then120
  store i32 1, i32* @flagi
  br label %next131

else130:                                          ; preds = %then120
  br label %forentry132

next131:                                          ; preds = %next135, %then129
  %123 = load i32, i32* @flagi
  %eq_cmp181 = icmp eq i32 %123, 1
  br i1 %eq_cmp181, label %then182, label %else183

forentry132:                                      ; preds = %else130
  store i32 1, i32* @j
  %124 = load i32, i32* @j
  %gt_cmp136 = icmp sgt i32 %124, 9
  br i1 %gt_cmp136, label %next135, label %forbody133

forbody133:                                       ; preds = %forend134, %forentry132
  %125 = load i32, i32* @i
  %mul137 = mul i32 %125, 1000
  %126 = load i32, i32* @j
  %mul138 = mul i32 %126, 100
  %add139 = add i32 %mul137, %mul138
  %add140 = add i32 %add139, 10
  %add141 = add i32 %add140, 1
  %sub142 = sub i32 %add141, 1
  %127 = getelementptr inbounds [10000000 x i8], [10000000 x i8]* @conditions, i32 0, i32 %sub142
  %128 = load i8, i8* %127
  %eq_cmp143 = icmp eq i8 %128, 0
  br i1 %eq_cmp143, label %then144, label %else145

forend134:                                        ; preds = %next178
  %129 = load i32, i32* @j
  %add179 = add i32 %129, 1
  store i32 %add179, i32* @j
  %130 = load i32, i32* @j
  %gt_cmp180 = icmp sgt i32 %130, 9
  br i1 %gt_cmp180, label %next135, label %forbody133

next135:                                          ; preds = %forend134, %then176, %then144, %forentry132
  br label %next131

then144:                                          ; preds = %forbody133
  br label %next135

else145:                                          ; preds = %forbody133
  br label %next146

next146:                                          ; preds = %else145
  store i32 1, i32* @flagj
  br label %forentry147

forentry147:                                      ; preds = %next146
  store i32 1, i32* @k
  %131 = load i32, i32* @k
  %gt_cmp151 = icmp sgt i32 %131, 9
  br i1 %gt_cmp151, label %next150, label %forbody148

forbody148:                                       ; preds = %forend149, %forentry147
  %132 = load i32, i32* @i
  %mul152 = mul i32 %132, 1000
  %133 = load i32, i32* @j
  %mul153 = mul i32 %133, 100
  %add154 = add i32 %mul152, %mul153
  %134 = load i32, i32* @k
  %mul155 = mul i32 %134, 10
  %add156 = add i32 %add154, %mul155
  %add157 = add i32 %add156, 1
  %sub158 = sub i32 %add157, 1
  %135 = getelementptr inbounds [10000000 x i8], [10000000 x i8]* @conditions, i32 0, i32 %sub158
  %136 = load i8, i8* %135
  %eq_cmp159 = icmp eq i8 %136, 0
  br i1 %eq_cmp159, label %then160, label %else161

forend149:                                        ; preds = %next172
  %137 = load i32, i32* @k
  %add173 = add i32 %137, 1
  store i32 %add173, i32* @k
  %138 = load i32, i32* @k
  %gt_cmp174 = icmp sgt i32 %138, 9
  br i1 %gt_cmp174, label %next150, label %forbody148

next150:                                          ; preds = %forend149, %then170, %then160, %forentry147
  %139 = load i32, i32* @flagj
  %eq_cmp175 = icmp eq i32 %139, 1
  br i1 %eq_cmp175, label %then176, label %else177

then160:                                          ; preds = %forbody148
  br label %next150

else161:                                          ; preds = %forbody148
  br label %next162

next162:                                          ; preds = %else161
  %140 = load i32, i32* @i
  %mul163 = mul i32 %140, 1000
  %141 = load i32, i32* @j
  %mul164 = mul i32 %141, 100
  %add165 = add i32 %mul163, %mul164
  %142 = load i32, i32* @k
  %mul166 = mul i32 %142, 10
  %add167 = add i32 %add165, %mul166
  %add168 = add i32 %add167, 1
  %143 = call i32 @find(i32 %add168)
  store i32 %143, i32* @flagk
  %144 = load i32, i32* @flagk
  %eq_cmp169 = icmp eq i32 %144, 0
  br i1 %eq_cmp169, label %then170, label %else171

then170:                                          ; preds = %next162
  store i32 0, i32* @flagj
  br label %next150

else171:                                          ; preds = %next162
  br label %next172

next172:                                          ; preds = %else171
  br label %forend149

then176:                                          ; preds = %next150
  store i32 1, i32* @flagi
  br label %next135

else177:                                          ; preds = %next150
  br label %next178

next178:                                          ; preds = %else177
  br label %forend134

then182:                                          ; preds = %next131
  %145 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.24, i32 0, i32 0), i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.tempstr.23, i32 0, i32 0))
  %146 = load i32, i32* @i
  %mul185 = mul i32 %146, 10
  %add186 = add i32 %mul185, 1
  %147 = call i32 @outputname(i32 %add186)
  %148 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_tempstr.26, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8], [1 x i8]* @.tempstr.25, i32 0, i32 0))
  br label %next184

else183:                                          ; preds = %next131
  br label %next184

next184:                                          ; preds = %else183, %then182
  br label %next122

then191:                                          ; preds = %next116
  %149 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.28, i32 0, i32 0), i8* getelementptr inbounds ([25 x i8], [25 x i8]* @.tempstr.27, i32 0, i32 0))
  %150 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_tempstr.30, i32 0, i32 0), i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.tempstr.29, i32 0, i32 0))
  br label %next193

else192:                                          ; preds = %next116
  br label %next193

next193:                                          ; preds = %else192, %then191
  ret i32 0
}

define i32 @outputname(i32 %y1) {
entry:
  %y = alloca i32
  store i32 %y1, i32* %y
  %outputname = alloca i32
  store i32 0, i32* %outputname
  br label %whileentry

whileentry:                                       ; preds = %next2, %entry
  br i1 true, label %whilebody, label %next

whilebody:                                        ; preds = %whileentry
  %0 = load i32, i32* %y
  %sub = sub i32 %0, 1
  %1 = getelementptr inbounds [10000 x i8], [10000 x i8]* @cname, i32 0, i32 %sub
  %2 = load i8, i8* %1
  store i8 %2, i8* @ch
  %3 = load i8, i8* @ch
  %eq_cmp = icmp eq i8 %3, 0
  br i1 %eq_cmp, label %then, label %else

next:                                             ; preds = %then, %whileentry
  %4 = load i32, i32* %outputname
  ret i32 %4

then:                                             ; preds = %whilebody
  br label %next

else:                                             ; preds = %whilebody
  br label %next2

next2:                                            ; preds = %else
  %5 = load i8, i8* @ch
  %6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr, i32 0, i32 0), i8 %5)
  %7 = load i32, i32* %y
  %add = add i32 %7, 1
  store i32 %add, i32* %y
  br label %whileentry
}

define i32 @outcon(i32 %y1) {
entry:
  %y = alloca i32
  store i32 %y1, i32* %y
  %outcon = alloca i32
  store i32 0, i32* %outcon
  br label %whileentry

whileentry:                                       ; preds = %next2, %entry
  br i1 true, label %whilebody, label %next

whilebody:                                        ; preds = %whileentry
  %0 = load i32, i32* %y
  %sub = sub i32 %0, 1
  %1 = getelementptr inbounds [10000000 x i8], [10000000 x i8]* @conditions, i32 0, i32 %sub
  %2 = load i8, i8* %1
  store i8 %2, i8* @ch
  %3 = load i8, i8* @ch
  %eq_cmp = icmp eq i8 %3, 0
  br i1 %eq_cmp, label %then, label %else

next:                                             ; preds = %then, %whileentry
  %4 = load i32, i32* %outcon
  ret i32 %4

then:                                             ; preds = %whilebody
  br label %next

else:                                             ; preds = %whilebody
  br label %next2

next2:                                            ; preds = %else
  %5 = load i8, i8* @ch
  %6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.1, i32 0, i32 0), i8 %5)
  %7 = load i32, i32* %y
  %add = add i32 %7, 1
  store i32 %add, i32* %y
  br label %whileentry
}

define i32 @cmp(i32 %y1, i32 %z2) {
entry:
  %y = alloca i32
  store i32 %y1, i32* %y
  %z = alloca i32
  store i32 %z2, i32* %z
  %cmp = alloca i32
  store i32 0, i32* %cmp
  store i32 1, i32* %cmp
  br label %whileentry

whileentry:                                       ; preds = %next8, %entry
  %0 = load i32, i32* %y
  %sub = sub i32 %0, 1
  %1 = getelementptr inbounds [10000000 x i8], [10000000 x i8]* @conditions, i32 0, i32 %sub
  %2 = load i8, i8* %1
  %ne_cmp = icmp ne i8 %2, 0
  %3 = load i32, i32* %z
  %sub3 = sub i32 %3, 1
  %4 = getelementptr inbounds [10000 x i8], [10000 x i8]* @cname, i32 0, i32 %sub3
  %5 = load i8, i8* %4
  %ne_cmp4 = icmp ne i8 %5, 0
  %or = or i1 %ne_cmp, %ne_cmp4
  br i1 %or, label %whilebody, label %next

whilebody:                                        ; preds = %whileentry
  %6 = load i32, i32* %y
  %sub5 = sub i32 %6, 1
  %7 = getelementptr inbounds [10000000 x i8], [10000000 x i8]* @conditions, i32 0, i32 %sub5
  %8 = load i8, i8* %7
  %9 = load i32, i32* %z
  %sub6 = sub i32 %9, 1
  %10 = getelementptr inbounds [10000 x i8], [10000 x i8]* @cname, i32 0, i32 %sub6
  %11 = load i8, i8* %10
  %ne_cmp7 = icmp ne i8 %8, %11
  br i1 %ne_cmp7, label %then, label %else

next:                                             ; preds = %then, %whileentry
  %12 = load i32, i32* %cmp
  ret i32 %12

then:                                             ; preds = %whilebody
  store i32 0, i32* %cmp
  br label %next

else:                                             ; preds = %whilebody
  br label %next8

next8:                                            ; preds = %else
  %13 = load i32, i32* %y
  %add = add i32 %13, 1
  store i32 %add, i32* %y
  %14 = load i32, i32* %z
  %add9 = add i32 %14, 1
  store i32 %add9, i32* %z
  br label %whileentry
}

define i32 @find(i32 %x1) {
entry:
  %x = alloca i32
  store i32 %x1, i32* %x
  %find = alloca i32
  store i32 0, i32* %find
  store i32 0, i32* %find
  br label %forentry

forentry:                                         ; preds = %entry
  store i32 1, i32* @l
  %0 = load i32, i32* @l
  %1 = load i32, i32* @count
  %sub = sub i32 %1, 1
  %gt_cmp = icmp sgt i32 %0, %sub
  br i1 %gt_cmp, label %next, label %forbody

forbody:                                          ; preds = %forend, %forentry
  %2 = load i32, i32* %x
  %3 = load i32, i32* @l
  %mul = mul i32 %3, 10
  %add = add i32 %mul, 1
  %4 = call i32 @cmp(i32 %2, i32 %add)
  %eq_cmp = icmp eq i32 %4, 1
  %5 = load i32, i32* @l
  %sub2 = sub i32 %5, 1
  %6 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %sub2
  %7 = load i32, i32* %6
  %gt_cmp3 = icmp sgt i32 %7, 0
  %and = and i1 %eq_cmp, %gt_cmp3
  br i1 %and, label %then, label %else

forend:                                           ; preds = %next4
  %8 = load i32, i32* @l
  %add5 = add i32 %8, 1
  store i32 %add5, i32* @l
  %9 = load i32, i32* @l
  %10 = load i32, i32* @count
  %sub6 = sub i32 %10, 1
  %gt_cmp7 = icmp sgt i32 %9, %sub6
  br i1 %gt_cmp7, label %next, label %forbody

next:                                             ; preds = %forend, %then, %forentry
  %11 = load i32, i32* %find
  ret i32 %11

then:                                             ; preds = %forbody
  store i32 1, i32* %find
  br label %next

else:                                             ; preds = %forbody
  br label %next4

next4:                                            ; preds = %else
  br label %forend
}
