int calculate_damage(const char *your_type, const char *opponent_type, int attack, int defense) 
{
    double effectiveness;
    
    if (your_type == "fire" && opponent_type == "grass") effectiveness = 2;
    else if (your_type == "grass" && opponent_type == "fire") effectiveness = 0.5;
  
    else if (your_type == "fire" && opponent_type == "water") effectiveness = 0.5;
    else if (your_type == "water" && opponent_type == "fire") effectiveness = 2;
  
    else if (your_type == "water" && opponent_type == "grass") effectiveness = 0.5;
    else if (your_type == "grass" && opponent_type == "water") effectiveness = 2;

    else if (your_type == "water" && opponent_type == "electric") effectiveness = 0.5;
    else if (your_type == "electric" && opponent_type == "water") effectiveness = 2;
    
    else if (your_type == opponent_type) effectiveness = 0.5;
    else effectiveness = 1;
    
    return (int) 50 * ( (float) attack / defense ) * effectiveness;
}
