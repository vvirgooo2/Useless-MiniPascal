program matrixMul;
var
    a, b, result : array [0 .. 125] of longint; // 矩阵变量
    rowA, rowB, columnA, columnB: longint; // 矩阵A/B的行列数
    i, j, k, idx1, idx2, idx3 : integer;
begin
    read(rowA, columnA); // 输入A的矩阵
    for i := 0 to rowA - 1 do
    begin
        for j := 0 to columnA - 1 do
        begin
            idx1 := i * columnA + j;
            read(a[idx1]);
        end;
    end;

    read(rowB, columnB); // 输入B的矩阵
    for i := 0 to rowB - 1 do
    begin
        for j := 0 to columnB - 1 do
        begin
            idx1 := i * columnB + j;
            read(b[idx1]);
        end;
    end;

    // 判断a和b是否可以执行矩阵相乘运算
    if (columnA = rowB) or ((columnA = 1) and (rowA = 1)) or ((columnB = 1) and (rowB = 1)) then
    begin
        // 可以执行c=a*b运算
        for i := 0 to rowA - 1 do
        begin
            for j := 0 to columnB - 1 do
            begin
                idx1 := i * columnB + j;
                result[idx1] := 0;
                for k := 0 to rowB - 1 do
                begin
                    idx2 := i * columnA + k;
                    idx3 := k * columnB + j;
                    result[idx1] := result[idx1] + (a[idx2] * b[idx3]);
                end;
            end;
        end;

        // 对c进行按格式输出
        for i := 0 to rowA - 1 do
        begin
            for j := 0 to columnB - 1 do
            begin
                idx1 := i * columnB + j;
                write(result[idx1]: 10);
            end;
            writeln(); // 换行
        end;
    end

    else
    begin
        // 无法进行矩阵乘法
        writeln('Incompatible Dimensions')
    end;
end.