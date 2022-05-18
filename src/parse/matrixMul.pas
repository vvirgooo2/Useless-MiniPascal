program matrixMul;
var
    a, b, result : array [0 .. 25, 0 .. 25] of longint;
    rowA, rowB, columnA, columnB: longint; 
    i, j, k, temp : integer;
begin
    read(rowA, columnA);
    for i := 0 to rowA - 1 do
    begin
        for j := 0 to columnA - 1 do
        begin
            read(a[i, j]);
        end;
    end;

    read(rowB, columnB); 
    for i := 0 to rowB - 1 do
    begin
        for j := 0 to columnB - 1 do
        begin
            read(b[i, j]);
        end;
    end;

    if (columnA = rowB) or ((columnA = 1) and (rowA = 1)) or ((columnB = 1) and (rowB = 1)) then
    begin
        for i := 0 to rowA - 1 do
        begin
            for j := 0 to columnB - 1 do
            begin
                result[i, j] := 0;
                for k := 0 to rowB - 1 do
                begin
                    result[i, j] := result[i, j] + (a[i, k] * b[k, j]);
                end;
            end;
        end;
        for i := 0 to rowA - 1 do
        begin
            for j := 0 to columnB - 1 do
            begin
                write(result[i, j]: 10)
            end;
            writeln();
        end;
    end

    else
    begin
        writeln('Incompatible Dimensions')
    end;
end.