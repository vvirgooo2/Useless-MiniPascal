program matrixMul;
var
    a, b, result : array [0 .. 1000] of integer; 
    rowA, rowB, columnA, columnB: integer;
    i, j, k, idx1, idx2, idx3 : integer;
begin
    read(rowA, columnA); 
    for i := 0 to rowA - 1 do
    begin
        for j := 0 to columnA - 1 do
        begin
            idx1 := i * columnA + j;
            read(a[idx1]);
        end;
    end;

    read(rowB, columnB); 
    for i := 0 to rowB - 1 do
    begin
        for j := 0 to columnB - 1 do
        begin
            idx1 := i * columnB + j;
            read(b[idx1]);
        end;
    end;

    if (columnA = rowB) then
    begin
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

        for i := 0 to rowA - 1 do
        begin
            for j := 0 to columnB - 1 do
            begin
                idx1 := i * columnB + j;
                write10d(result[idx1]);
            end;
            writeln(""); 
        end;
    end;

    else
    begin
        writeln("Incompatible Dimensions");
    end;
end.