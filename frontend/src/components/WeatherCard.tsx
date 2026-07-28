import { Thermometer, Droplets, Wind, Cloud, MapPin } from "lucide-react";

import type { Weather } from "../types/Weather";
import WeatherInfoCard from "./WeatherInfoCard";
import { getWeatherIcon } from "../utils/weatherIcon";

interface WeatherCardProps {
  weather: Weather;
}

function WeatherCard({ weather }: WeatherCardProps) {
  const cards = [
    {
      title: "Temperature",
      value: `${weather.temperatureF}°F`,
      icon: <Thermometer size={32} className="text-white" strokeWidth={1.5} />,
    },
    {
      title: "Feels Like",
      value: `${weather.feelsLikeF}°F`,
      icon: <Thermometer size={32} className="text-white" strokeWidth={1.5} />,
    },
    {
      title: "Humidity",
      value: `${weather.humidity}%`,
      icon: <Droplets size={32} className="text-white" strokeWidth={1.5} />,
    },
    {
      title: "Wind",
      value: `${weather.windSpeedMph} mph`,
      icon: <Wind size={32} className="text-white" strokeWidth={1.5} />,
    },
  ];

  return (
    <div
      className="
        bg-white/10
        backdrop-blur-xl
        border
        border-white/20
        rounded-3xl
        p-8
        text-white
        shadow-2xl
        w-96
        transition
        duration-300
        hover:shadow-white/10
      "
    >
      <div className="flex items-center justify-center gap-2 mb-6">
        <MapPin size={28} className="text-white" strokeWidth={1.5} />

        <h2 className="text-3xl font-bold">{weather.city}</h2>
      </div>

      <div className="grid grid-cols-2 gap-4">
        {cards.map((card) => (
          <WeatherInfoCard
            key={card.title}
            icon={card.icon}
            title={card.title}
            value={card.value}
          />
        ))}
      </div>

      <div className="mt-4">
        <WeatherInfoCard
          icon={getWeatherIcon(weather.condition)}
          title="Conditions"
          value={weather.condition}
        />
      </div>
    </div>
  );
}

export default WeatherCard;
