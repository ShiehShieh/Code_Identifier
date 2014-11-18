           var bt,rt,i,j,k,sumb:longint;//bt 提供木板的数量 rt 所需木料的数目 sumb 提供木板的总长度
r,sum:array[0..1023]of longint;//r[i] 第i每个木料的长度 sum[i] 1 到 i的个木料的总长度
b:array[1..50]of longint;//b[i] 第i个提供木板的长度
procedure swap(var x,y:longint);
var z:longint;
begin
    z:=x; x:=y; y:=z;
end;
function make(s,x,m:longint):boolean;
var i,ni,num:longint;
begin
    if x=0 then exit(true);//k个rail都被切完了
    for i:=bt downto m do //先切大的board要比先切小的更快
      if b[i]>=r[x] then //第x个rail可以切b[i]
      begin
          dec(b[i],r[x]);
          if b[i]<r[1] then
          begin
             num:=s+b[i];//迭代的思想体现
             if num+sum[k]>sumb then //切剩下的board(无法再切下rail)，统计一下总和。如果大于board的长度总和-rail长度总和，一定无解。
             begin
                 inc(b[i],r[x]);
                 continue;
             end;
          end
          else num:=s;//迭代的思想体现
          if r[x]=r[x-1] then //若有rail[x-1]=rail[x]，则rail[x-1]对应的board一定大于等于rail[x]对应的board。可以通过这种方法剪掉很多冗余的枝条。
           ni:=i //迭代的思想体现
          else ni:=1;
          if make(num,x-1,ni) then exit(true);
          inc(b[i],r[x]); //回溯
      end;
    exit(false);
end;
begin
      //while not eof do begin
        read(bt); sumb:=0;
        for i:=1 to bt do
        begin read(b[i]); inc(sumb,b[i]); end;
        for i:=1 to bt-1 do
          for j:=i+1 to bt do
            if b[i]>b[j] then
              swap(b[i],b[j]);//简单排序一下
        read(rt);
        for i:=1 to rt do read(r[i]);
        sum[0]:=0;
        for i:=1 to rt do begin
            k:=i;
            for j:=i+1 to rt do
              if r[k]>r[j] then
                k:=j;
            swap(r[k],r[i]);
            sum[i]:=sum[i-1]+r[i];
            if sum[i]>sumb then
            begin
                rt:=i-1;
                break;
            end;
        end;//找出rail最大可以切的个数
        k:=rt;
        while not(make(0,k,1)) do dec(k); //先切大的rail比先切小的rail更容易提前出解
        writeln(k);
       //end;
end.                            
