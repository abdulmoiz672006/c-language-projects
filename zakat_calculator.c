#include<stdio.h>
int main(){
    float gold_zakat=0.0f, silver_zakat=0.0f, assets_zakat=0.0f;
float sahib_e_nisab_amount,gold_weight,gold_cost_per_tola,silver_weight,silver_cost_per_tola,other_assets;
float zakatt_amount;
printf("Enter the weight of gold (in tola): ");
scanf("%f",&gold_weight);
printf("Enter the price of gold per tola: ");
scanf("%f",&gold_cost_per_tola);
printf("Enter the weight of silver: ");
scanf("%f",&silver_weight);
printf("Enter the price of silver per tola: ");
scanf("%f",&silver_cost_per_tola);
printf("Enter price of other assets: ");
scanf("%f",&other_assets);
float gold_price=gold_cost_per_tola*gold_weight;
float silver_price=silver_cost_per_tola*silver_weight;
 float nisab_gold = 7.5 * gold_cost_per_tola;
    float nisab_silver = 52.5 * silver_cost_per_tola;
if (gold_price >= nisab_gold){
     gold_zakat = 0.025* gold_price;
}
else if(silver_price>=nisab_silver ){
     silver_zakat=0.025*silver_price;
}
else if(other_assets>=nisab_silver){
    assets_zakat=0.025*other_assets;
}
else{
  printf("You are not eligible to pay zakatt.");
}
zakatt_amount=gold_zakat+silver_zakat+assets_zakat;
printf("\nYour zakat amount is:Rs. %.2f\n\n\n*****************************************", zakatt_amount);
return ;
}
