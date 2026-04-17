select e2.product_name , e1.year , e1.price
from Sales e1 inner join Product e2
on e1.product_id = e2.product_id;