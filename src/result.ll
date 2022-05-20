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

whileentry:                                       ; preds = %next67, %entry
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
  %6 = sub i32 %add, 1
  %7 = getelementptr inbounds [10000 x i8], [10000 x i8]* @cname, i32 0, i32 %6
  %8 = load i8, i8* @ch
  store i8 %8, i8* %7
  %9 = load i32, i32* @len
  %add6 = add i32 %9, 1
  store i32 %add6, i32* @len
  %10 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.3, i32 0, i32 0), i8* @ch)
  br label %whileentry3

next5:                                            ; preds = %whileentry3
  %11 = load i32, i32* @count
  %12 = sub i32 %11, 1
  %13 = getelementptr inbounds [1000 x i32], [1000 x i32]* @credits, i32 0, i32 %12
  %14 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.4, i32 0, i32 0), i32* %13)
  %15 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.5, i32 0, i32 0), i8* @ch)
  %16 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.6, i32 0, i32 0), i8* @ch)
  %17 = load i8, i8* @ch
  %ne_cmp7 = icmp ne i8 %17, 124
  br i1 %ne_cmp7, label %then8, label %else9

then8:                                            ; preds = %next5
  store i32 1, i32* @orcount
  store i32 1, i32* @andcount
  store i32 1, i32* @namec
  br label %whileentry11

else9:                                            ; preds = %next5
  br label %next10

next10:                                           ; preds = %else9, %next13
  %18 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.8, i32 0, i32 0), i8* @ch)
  %19 = load i8, i8* @ch
  %eq_cmp44 = icmp eq i8 %19, 65
  br i1 %eq_cmp44, label %then45, label %else46

whileentry11:                                     ; preds = %next43, %then8
  br i1 true, label %whilebody12, label %next13

whilebody12:                                      ; preds = %whileentry11
  %20 = load i8, i8* @ch
  %ne_cmp14 = icmp ne i8 %20, 44
  %21 = load i8, i8* @ch
  %ne_cmp15 = icmp ne i8 %21, 59
  %and = and i1 %ne_cmp14, %ne_cmp15
  %22 = load i8, i8* @ch
  %ne_cmp16 = icmp ne i8 %22, 124
  %and17 = and i1 %and, %ne_cmp16
  br i1 %and17, label %then18, label %else19

next13:                                           ; preds = %then41, %whileentry11
  br label %next10

then18:                                           ; preds = %whilebody12
  %23 = load i32, i32* @count
  %mul21 = mul i32 %23, 1000
  %24 = load i32, i32* @orcount
  %mul22 = mul i32 %24, 100
  %add23 = add i32 %mul21, %mul22
  %25 = load i32, i32* @andcount
  %mul24 = mul i32 %25, 10
  %add25 = add i32 %add23, %mul24
  %26 = load i32, i32* @namec
  %add26 = add i32 %add25, %26
  %27 = sub i32 %add26, 1
  %28 = getelementptr inbounds [10000000 x i8], [10000000 x i8]* @conditions, i32 0, i32 %27
  %29 = load i8, i8* @ch
  store i8 %29, i8* %28
  %30 = load i32, i32* @namec
  %add27 = add i32 %30, 1
  store i32 %add27, i32* @namec
  br label %next20

else19:                                           ; preds = %whilebody12
  br label %next20

next20:                                           ; preds = %else19, %then18
  %31 = load i8, i8* @ch
  %eq_cmp28 = icmp eq i8 %31, 44
  br i1 %eq_cmp28, label %then29, label %else30

then29:                                           ; preds = %next20
  %32 = load i32, i32* @andcount
  %add32 = add i32 %32, 1
  store i32 %add32, i32* @andcount
  store i32 1, i32* @namec
  br label %next31

else30:                                           ; preds = %next20
  br label %next31

next31:                                           ; preds = %else30, %then29
  %33 = load i8, i8* @ch
  %eq_cmp33 = icmp eq i8 %33, 59
  %34 = load i8, i8* @ch
  %eq_cmp34 = icmp eq i8 %34, 124
  %or35 = or i1 %eq_cmp33, %eq_cmp34
  br i1 %or35, label %then36, label %else37

then36:                                           ; preds = %next31
  %35 = load i32, i32* @orcount
  %add39 = add i32 %35, 1
  store i32 %add39, i32* @orcount
  store i32 1, i32* @andcount
  store i32 1, i32* @namec
  br label %next38

else37:                                           ; preds = %next31
  br label %next38

next38:                                           ; preds = %else37, %then36
  %36 = load i8, i8* @ch
  %eq_cmp40 = icmp eq i8 %36, 124
  br i1 %eq_cmp40, label %then41, label %else42

then41:                                           ; preds = %next38
  br label %next13

else42:                                           ; preds = %next38
  br label %next43

next43:                                           ; preds = %else42
  %37 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.7, i32 0, i32 0), i8* @ch)
  br label %whileentry11

then45:                                           ; preds = %next10
  %38 = load i32, i32* @count
  %39 = sub i32 %38, 1
  %40 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %39
  store i32 4, i32* %40
  br label %next47

else46:                                           ; preds = %next10
  br label %next47

next47:                                           ; preds = %else46, %then45
  %41 = load i8, i8* @ch
  %eq_cmp48 = icmp eq i8 %41, 66
  br i1 %eq_cmp48, label %then49, label %else50

then49:                                           ; preds = %next47
  %42 = load i32, i32* @count
  %43 = sub i32 %42, 1
  %44 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %43
  store i32 3, i32* %44
  br label %next51

else50:                                           ; preds = %next47
  br label %next51

next51:                                           ; preds = %else50, %then49
  %45 = load i8, i8* @ch
  %eq_cmp52 = icmp eq i8 %45, 67
  br i1 %eq_cmp52, label %then53, label %else54

then53:                                           ; preds = %next51
  %46 = load i32, i32* @count
  %47 = sub i32 %46, 1
  %48 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %47
  store i32 2, i32* %48
  br label %next55

else54:                                           ; preds = %next51
  br label %next55

next55:                                           ; preds = %else54, %then53
  %49 = load i8, i8* @ch
  %eq_cmp56 = icmp eq i8 %49, 68
  br i1 %eq_cmp56, label %then57, label %else58

then57:                                           ; preds = %next55
  %50 = load i32, i32* @count
  %51 = sub i32 %50, 1
  %52 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %51
  store i32 1, i32* %52
  br label %next59

else58:                                           ; preds = %next55
  br label %next59

next59:                                           ; preds = %else58, %then57
  %53 = load i8, i8* @ch
  %eq_cmp60 = icmp eq i8 %53, 70
  br i1 %eq_cmp60, label %then61, label %else62

then61:                                           ; preds = %next59
  %54 = load i32, i32* @count
  %55 = sub i32 %54, 1
  %56 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %55
  store i32 0, i32* %56
  br label %next63

else62:                                           ; preds = %next59
  br label %next63

next63:                                           ; preds = %else62, %then61
  %57 = load i8, i8* @ch
  %eq_cmp64 = icmp eq i8 %57, 10
  br i1 %eq_cmp64, label %then65, label %else66

then65:                                           ; preds = %next63
  %58 = load i32, i32* @count
  %59 = sub i32 %58, 1
  %60 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %59
  store i32 -1, i32* %60
  br label %next67

else66:                                           ; preds = %next63
  %61 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.9, i32 0, i32 0), i8* @ch)
  br label %next67

next67:                                           ; preds = %else66, %then65
  %62 = load i32, i32* @count
  %add68 = add i32 %62, 1
  store i32 %add68, i32* @count
  br label %whileentry

forentry:                                         ; preds = %next
  store i32 1, i32* @i
  %63 = load i32, i32* @i
  %64 = load i32, i32* @count
  %sub = sub i32 %64, 1
  %gt_cmp = icmp sgt i32 %63, %sub
  br i1 %gt_cmp, label %next69, label %forbody

forbody:                                          ; preds = %forend, %forentry
  %65 = load i32, i32* @i
  %66 = sub i32 %65, 1
  %67 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %66
  %68 = load i32, i32* %67
  %eq_cmp70 = icmp eq i32 %68, 0
  br i1 %eq_cmp70, label %then71, label %else72

forend:                                           ; preds = %next83
  %69 = load i32, i32* @i
  %add87 = add i32 %69, 1
  store i32 %add87, i32* @i
  %70 = load i32, i32* @i
  %71 = load i32, i32* @count
  %sub88 = sub i32 %71, 1
  %gt_cmp89 = icmp sgt i32 %70, %sub88
  br i1 %gt_cmp89, label %next69, label %forbody

next69:                                           ; preds = %forend, %forentry
  %72 = load i32, i32* @total
  %73 = sitofp i32 %72 to double
  store double %73, double* @totalF
  %74 = load i32, i32* @attempt
  %75 = sitofp i32 %74 to double
  store double %75, double* @attemptF
  %76 = load i32, i32* @attempt
  %gt_cmp90 = icmp sgt i32 %76, 0
  br i1 %gt_cmp90, label %then91, label %else92

then71:                                           ; preds = %forbody
  %77 = load i32, i32* @attempt
  %78 = load i32, i32* @i
  %79 = sub i32 %78, 1
  %80 = getelementptr inbounds [1000 x i32], [1000 x i32]* @credits, i32 0, i32 %79
  %81 = load i32, i32* %80
  %add74 = add i32 %77, %81
  store i32 %add74, i32* @attempt
  br label %next73

else72:                                           ; preds = %forbody
  br label %next73

next73:                                           ; preds = %else72, %then71
  %82 = load i32, i32* @i
  %83 = sub i32 %82, 1
  %84 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %83
  %85 = load i32, i32* %84
  %gt_cmp75 = icmp sgt i32 %85, 0
  br i1 %gt_cmp75, label %then76, label %else77

then76:                                           ; preds = %next73
  %86 = load i32, i32* @attempt
  %87 = load i32, i32* @i
  %88 = sub i32 %87, 1
  %89 = getelementptr inbounds [1000 x i32], [1000 x i32]* @credits, i32 0, i32 %88
  %90 = load i32, i32* %89
  %add79 = add i32 %86, %90
  store i32 %add79, i32* @attempt
  %91 = load i32, i32* @complete
  %92 = load i32, i32* @i
  %93 = sub i32 %92, 1
  %94 = getelementptr inbounds [1000 x i32], [1000 x i32]* @credits, i32 0, i32 %93
  %95 = load i32, i32* %94
  %add80 = add i32 %91, %95
  store i32 %add80, i32* @complete
  br label %next78

else77:                                           ; preds = %next73
  br label %next78

next78:                                           ; preds = %else77, %then76
  %96 = load i32, i32* @i
  %97 = sub i32 %96, 1
  %98 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %97
  %99 = load i32, i32* %98
  %ge_cmp = icmp sge i32 %99, 0
  br i1 %ge_cmp, label %then81, label %else82

then81:                                           ; preds = %next78
  %100 = load i32, i32* @total
  %101 = load i32, i32* @i
  %102 = sub i32 %101, 1
  %103 = getelementptr inbounds [1000 x i32], [1000 x i32]* @credits, i32 0, i32 %102
  %104 = load i32, i32* %103
  %105 = load i32, i32* @i
  %106 = sub i32 %105, 1
  %107 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %106
  %108 = load i32, i32* %107
  %mul84 = mul i32 %104, %108
  %add85 = add i32 %100, %mul84
  store i32 %add85, i32* @total
  br label %next83

else82:                                           ; preds = %next78
  br label %next83

next83:                                           ; preds = %else82, %then81
  %109 = load i32, i32* @need
  %110 = load i32, i32* @i
  %111 = sub i32 %110, 1
  %112 = getelementptr inbounds [1000 x i32], [1000 x i32]* @credits, i32 0, i32 %111
  %113 = load i32, i32* %112
  %add86 = add i32 %109, %113
  store i32 %add86, i32* @need
  br label %forend

then91:                                           ; preds = %next69
  %114 = load double, double* @totalF
  %115 = load double, double* @attemptF
  %div = fdiv double %114, %115
  store double %div, double* @GPA
  br label %next93

else92:                                           ; preds = %next69
  br label %next93

next93:                                           ; preds = %else92, %then91
  %116 = load i32, i32* @need
  %117 = load i32, i32* @complete
  %sub94 = sub i32 %116, %117
  store i32 %sub94, i32* @need
  %118 = load double, double* @GPA
  %119 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([9 x i8], [9 x i8]* @_tempstr.10, i32 0, i32 0), i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.tempstr, i32 0, i32 0), double %118)
  %120 = load i32, i32* @attempt
  %121 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @_tempstr.12, i32 0, i32 0), i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.tempstr.11, i32 0, i32 0), i32 %120)
  %122 = load i32, i32* @complete
  %123 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @_tempstr.14, i32 0, i32 0), i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.tempstr.13, i32 0, i32 0), i32 %122)
  %124 = load i32, i32* @need
  %125 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @_tempstr.16, i32 0, i32 0), i8* getelementptr inbounds ([20 x i8], [20 x i8]* @.tempstr.15, i32 0, i32 0), i32 %124)
  %126 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_tempstr.18, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8], [1 x i8]* @.tempstr.17, i32 0, i32 0))
  %127 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.20, i32 0, i32 0), i8* getelementptr inbounds ([25 x i8], [25 x i8]* @.tempstr.19, i32 0, i32 0))
  %128 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_tempstr.22, i32 0, i32 0), i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.tempstr.21, i32 0, i32 0))
  store i32 1, i32* @j
  store i32 1, i32* @k
  br label %forentry95

forentry95:                                       ; preds = %next93
  store i32 1, i32* @i
  %129 = load i32, i32* @i
  %130 = load i32, i32* @count
  %sub99 = sub i32 %130, 1
  %gt_cmp100 = icmp sgt i32 %129, %sub99
  br i1 %gt_cmp100, label %next98, label %forbody96

forbody96:                                        ; preds = %forend97, %forentry95
  store i32 0, i32* @flagi
  %131 = load i32, i32* @i
  %132 = sub i32 %131, 1
  %133 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %132
  %134 = load i32, i32* %133
  %le_cmp = icmp sle i32 %134, 0
  br i1 %le_cmp, label %then101, label %else102

forend97:                                         ; preds = %next103
  %135 = load i32, i32* @i
  %add165 = add i32 %135, 1
  store i32 %add165, i32* @i
  %136 = load i32, i32* @i
  %137 = load i32, i32* @count
  %sub166 = sub i32 %137, 1
  %gt_cmp167 = icmp sgt i32 %136, %sub166
  br i1 %gt_cmp167, label %next98, label %forbody96

next98:                                           ; preds = %forend97, %forentry95
  %138 = load i32, i32* @need
  %eq_cmp168 = icmp eq i32 %138, 0
  br i1 %eq_cmp168, label %then169, label %else170

then101:                                          ; preds = %forbody96
  store i32 0, i32* @flagi
  %139 = load i32, i32* @i
  %mul104 = mul i32 %139, 1000
  %add105 = add i32 %mul104, 100
  %add106 = add i32 %add105, 10
  %add107 = add i32 %add106, 1
  %140 = sub i32 %add107, 1
  %141 = getelementptr inbounds [10000000 x i8], [10000000 x i8]* @conditions, i32 0, i32 %140
  %142 = load i8, i8* %141
  %eq_cmp108 = icmp eq i8 %142, 0
  br i1 %eq_cmp108, label %then109, label %else110

else102:                                          ; preds = %forbody96
  br label %next103

next103:                                          ; preds = %else102, %next162
  br label %forend97

then109:                                          ; preds = %then101
  store i32 1, i32* @flagi
  br label %next111

else110:                                          ; preds = %then101
  br label %forentry112

next111:                                          ; preds = %next115, %then109
  %143 = load i32, i32* @flagi
  %eq_cmp159 = icmp eq i32 %143, 1
  br i1 %eq_cmp159, label %then160, label %else161

forentry112:                                      ; preds = %else110
  store i32 1, i32* @j
  %144 = load i32, i32* @j
  %gt_cmp116 = icmp sgt i32 %144, 9
  br i1 %gt_cmp116, label %next115, label %forbody113

forbody113:                                       ; preds = %forend114, %forentry112
  %145 = load i32, i32* @i
  %mul117 = mul i32 %145, 1000
  %146 = load i32, i32* @j
  %mul118 = mul i32 %146, 100
  %add119 = add i32 %mul117, %mul118
  %add120 = add i32 %add119, 10
  %add121 = add i32 %add120, 1
  %147 = sub i32 %add121, 1
  %148 = getelementptr inbounds [10000000 x i8], [10000000 x i8]* @conditions, i32 0, i32 %147
  %149 = load i8, i8* %148
  %eq_cmp122 = icmp eq i8 %149, 0
  br i1 %eq_cmp122, label %then123, label %else124

forend114:                                        ; preds = %next156
  %150 = load i32, i32* @j
  %add157 = add i32 %150, 1
  store i32 %add157, i32* @j
  %151 = load i32, i32* @j
  %gt_cmp158 = icmp sgt i32 %151, 9
  br i1 %gt_cmp158, label %next115, label %forbody113

next115:                                          ; preds = %forend114, %then154, %then123, %forentry112
  br label %next111

then123:                                          ; preds = %forbody113
  br label %next115

else124:                                          ; preds = %forbody113
  br label %next125

next125:                                          ; preds = %else124
  store i32 1, i32* @flagj
  br label %forentry126

forentry126:                                      ; preds = %next125
  store i32 1, i32* @k
  %152 = load i32, i32* @k
  %gt_cmp130 = icmp sgt i32 %152, 9
  br i1 %gt_cmp130, label %next129, label %forbody127

forbody127:                                       ; preds = %forend128, %forentry126
  %153 = load i32, i32* @i
  %mul131 = mul i32 %153, 1000
  %154 = load i32, i32* @j
  %mul132 = mul i32 %154, 100
  %add133 = add i32 %mul131, %mul132
  %155 = load i32, i32* @k
  %mul134 = mul i32 %155, 10
  %add135 = add i32 %add133, %mul134
  %add136 = add i32 %add135, 1
  %156 = sub i32 %add136, 1
  %157 = getelementptr inbounds [10000000 x i8], [10000000 x i8]* @conditions, i32 0, i32 %156
  %158 = load i8, i8* %157
  %eq_cmp137 = icmp eq i8 %158, 0
  br i1 %eq_cmp137, label %then138, label %else139

forend128:                                        ; preds = %next150
  %159 = load i32, i32* @k
  %add151 = add i32 %159, 1
  store i32 %add151, i32* @k
  %160 = load i32, i32* @k
  %gt_cmp152 = icmp sgt i32 %160, 9
  br i1 %gt_cmp152, label %next129, label %forbody127

next129:                                          ; preds = %forend128, %then148, %then138, %forentry126
  %161 = load i32, i32* @flagj
  %eq_cmp153 = icmp eq i32 %161, 1
  br i1 %eq_cmp153, label %then154, label %else155

then138:                                          ; preds = %forbody127
  br label %next129

else139:                                          ; preds = %forbody127
  br label %next140

next140:                                          ; preds = %else139
  %162 = load i32, i32* @i
  %mul141 = mul i32 %162, 1000
  %163 = load i32, i32* @j
  %mul142 = mul i32 %163, 100
  %add143 = add i32 %mul141, %mul142
  %164 = load i32, i32* @k
  %mul144 = mul i32 %164, 10
  %add145 = add i32 %add143, %mul144
  %add146 = add i32 %add145, 1
  %165 = call i32 @find(i32 %add146)
  store i32 %165, i32* @flagk
  %166 = load i32, i32* @flagk
  %eq_cmp147 = icmp eq i32 %166, 0
  br i1 %eq_cmp147, label %then148, label %else149

then148:                                          ; preds = %next140
  store i32 0, i32* @flagj
  br label %next129

else149:                                          ; preds = %next140
  br label %next150

next150:                                          ; preds = %else149
  br label %forend128

then154:                                          ; preds = %next129
  store i32 1, i32* @flagi
  br label %next115

else155:                                          ; preds = %next129
  br label %next156

next156:                                          ; preds = %else155
  br label %forend114

then160:                                          ; preds = %next111
  %167 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.24, i32 0, i32 0), i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.tempstr.23, i32 0, i32 0))
  %168 = load i32, i32* @i
  %mul163 = mul i32 %168, 10
  %add164 = add i32 %mul163, 1
  %169 = call i32 @outputname(i32 %add164)
  %170 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_tempstr.26, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8], [1 x i8]* @.tempstr.25, i32 0, i32 0))
  br label %next162

else161:                                          ; preds = %next111
  br label %next162

next162:                                          ; preds = %else161, %then160
  br label %next103

then169:                                          ; preds = %next98
  %171 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.28, i32 0, i32 0), i8* getelementptr inbounds ([25 x i8], [25 x i8]* @.tempstr.27, i32 0, i32 0))
  %172 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_tempstr.30, i32 0, i32 0), i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.tempstr.29, i32 0, i32 0))
  br label %next171

else170:                                          ; preds = %next98
  br label %next171

next171:                                          ; preds = %else170, %then169
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
  %1 = sub i32 %0, 1
  %2 = getelementptr inbounds [10000 x i8], [10000 x i8]* @cname, i32 0, i32 %1
  %3 = load i8, i8* %2
  store i8 %3, i8* @ch
  %4 = load i8, i8* @ch
  %eq_cmp = icmp eq i8 %4, 0
  br i1 %eq_cmp, label %then, label %else

next:                                             ; preds = %then, %whileentry
  %5 = load i32, i32* %outputname
  ret i32 %5

then:                                             ; preds = %whilebody
  br label %next

else:                                             ; preds = %whilebody
  br label %next2

next2:                                            ; preds = %else
  %6 = load i8, i8* @ch
  %7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr, i32 0, i32 0), i8 %6)
  %8 = load i32, i32* %y
  %add = add i32 %8, 1
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
  %1 = sub i32 %0, 1
  %2 = getelementptr inbounds [10000000 x i8], [10000000 x i8]* @conditions, i32 0, i32 %1
  %3 = load i8, i8* %2
  store i8 %3, i8* @ch
  %4 = load i8, i8* @ch
  %eq_cmp = icmp eq i8 %4, 0
  br i1 %eq_cmp, label %then, label %else

next:                                             ; preds = %then, %whileentry
  %5 = load i32, i32* %outcon
  ret i32 %5

then:                                             ; preds = %whilebody
  br label %next

else:                                             ; preds = %whilebody
  br label %next2

next2:                                            ; preds = %else
  %6 = load i8, i8* @ch
  %7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_tempstr.1, i32 0, i32 0), i8 %6)
  %8 = load i32, i32* %y
  %add = add i32 %8, 1
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

whileentry:                                       ; preds = %next5, %entry
  %0 = load i32, i32* %y
  %1 = sub i32 %0, 1
  %2 = getelementptr inbounds [10000000 x i8], [10000000 x i8]* @conditions, i32 0, i32 %1
  %3 = load i8, i8* %2
  %ne_cmp = icmp ne i8 %3, 0
  %4 = load i32, i32* %z
  %5 = sub i32 %4, 1
  %6 = getelementptr inbounds [10000 x i8], [10000 x i8]* @cname, i32 0, i32 %5
  %7 = load i8, i8* %6
  %ne_cmp3 = icmp ne i8 %7, 0
  %or = or i1 %ne_cmp, %ne_cmp3
  br i1 %or, label %whilebody, label %next

whilebody:                                        ; preds = %whileentry
  %8 = load i32, i32* %y
  %9 = sub i32 %8, 1
  %10 = getelementptr inbounds [10000000 x i8], [10000000 x i8]* @conditions, i32 0, i32 %9
  %11 = load i8, i8* %10
  %12 = load i32, i32* %z
  %13 = sub i32 %12, 1
  %14 = getelementptr inbounds [10000 x i8], [10000 x i8]* @cname, i32 0, i32 %13
  %15 = load i8, i8* %14
  %ne_cmp4 = icmp ne i8 %11, %15
  br i1 %ne_cmp4, label %then, label %else

next:                                             ; preds = %then, %whileentry
  %16 = load i32, i32* %cmp
  ret i32 %16

then:                                             ; preds = %whilebody
  store i32 0, i32* %cmp
  br label %next

else:                                             ; preds = %whilebody
  br label %next5

next5:                                            ; preds = %else
  %17 = load i32, i32* %y
  %add = add i32 %17, 1
  store i32 %add, i32* %y
  %18 = load i32, i32* %z
  %add6 = add i32 %18, 1
  store i32 %add6, i32* %z
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
  %6 = sub i32 %5, 1
  %7 = getelementptr inbounds [1000 x i32], [1000 x i32]* @score, i32 0, i32 %6
  %8 = load i32, i32* %7
  %gt_cmp2 = icmp sgt i32 %8, 0
  %and = and i1 %eq_cmp, %gt_cmp2
  br i1 %and, label %then, label %else

forend:                                           ; preds = %next3
  %9 = load i32, i32* @l
  %add4 = add i32 %9, 1
  store i32 %add4, i32* @l
  %10 = load i32, i32* @l
  %11 = load i32, i32* @count
  %sub5 = sub i32 %11, 1
  %gt_cmp6 = icmp sgt i32 %10, %sub5
  br i1 %gt_cmp6, label %next, label %forbody

next:                                             ; preds = %forend, %then, %forentry
  %12 = load i32, i32* %find
  ret i32 %12

then:                                             ; preds = %forbody
  store i32 1, i32* %find
  br label %next

else:                                             ; preds = %forbody
  br label %next3

next3:                                            ; preds = %else
  br label %forend
}
