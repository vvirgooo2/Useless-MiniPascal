program matrixMul;
var
    a, b, result : array [0 .. 25, 0 .. 25] of integer; // 矩阵变量
    rowA, rowB, columnA, columnB: longint; // 矩阵A/B的行列数
    i, j, k : integer;
begin
    read(rowA, columnA); // 输入A的矩阵
    for i := 0 to rowA - 1 do
    begin
        for j := 0 to columnA - 1 do
        begin
            read(a[i, j]);
        end;
    end;

    read(rowB, columnB); // 输入B的矩阵
    for i := 0 to rowB - 1 do
    begin
        for j := 0 to columnB - 1 do
        begin
            read(b[i, j]);
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
                result[i, j] := 0;
                for k := 0 to rowB - 1 do
                begin
                    result[i, j] := result[i, j] + a[i, k] * b[k, j];
                end;
            end;
        end;

        // 对c进行按格式输出
        for i := 0 to rowA - 1 do
        begin
            for j := 0 to columnB - 1 do
            begin
                write(result[i, j]: 10)
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