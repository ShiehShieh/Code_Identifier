const
  maxn=200;

var
  sum:array[1..maxn,1..maxn]of longint;
  f:array[0..40,0..maxn]of longint;
  check:array[1..maxn,1..6]of boolean;
  w:array[1..6]of string;
  str:string;
  k,p,n:integer;

  procedure init;
  var
    i:integer;
    s:string;
  begin
    str:='';
    readln(p,k);
    for i:=1 to p do
      begin
       readln(s);
       str:=str+s;
      end;
    readln(n);
    for i:=1 to n do readln(w[i]);
  end;

    function find(i,j:integer):boolean;
    var
      k:integer;
    begin
      if length(str)-i+1<length(w[j]) then exit(false);
      find:=true;
      for k:=i to i+length(w[j])-1 do
        if str[k]<>w[j][k-i+1] then exit(false);
    end;

  procedure main;
  var
    i,j,l,l2:integer;
  begin
    fillchar(check,sizeof(check),0);
    fillchar(f,sizeof(f),0);
    fillchar(sum,sizeof(sum),0); // [1..length,1..length]
    for i:=1 to length(str) do
      begin
        for j:=1 to n do
          if find(i,j) then check[i,j]:=true;
      end;
    for i:=1 to length(str) do
      for j:=i to length(str) do
        begin
          for l:=i to j do
            begin
              for l2:=1 to n do
                if (j-l+1>=length(w[l2]))and(check[l,l2]) then
                  begin
                    inc(sum[i,j]);
                    break;
                  end;
            end;
        end;
    for i:=1 to p*20 do
      begin
        for j:=1 to k do
          begin
            if j>i then break;
            for l:=j-1 to i-1 do
              if f[j-1,l]+sum[l+1,i]>f[j,i] then
                f[j,i]:=f[j-1,l]+sum[l+1,i];
          end;
      end;
  end;

  procedure outit;
  begin
    writeln(f[k,length(str)]);
  end;

begin
  init;
  main;
  outit;
end.

