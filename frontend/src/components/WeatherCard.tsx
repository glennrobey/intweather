import type { Weather } from "../types/Weather";

interface WeatherCardProps {
  weather: Weather;
}

function WeatherCard({ weather }: WeatherCardProps) {
  return (
    <div
      className="
        bg-white/10
        backdrop-blur-lg
        border
        border-white/20
        rounded-3xl
        p-8
        text-white
        shadow-2xl
        w-96
      "
    >
      <h2 className="text-2xl font-semibold">{weather.city}</h2>

      <h1 className="text-7xl font-bold mt-4">{weather.temperatureF}°</h1>

      <p className="text-xl text-gray-200">{weather.condition}</p>

      <div className="grid grid-cols-2 gap-4 mt-6">
        <div className="bg-white/10 rounded-xl p-4">
          <p className="text-gray-300">Feels Like</p>
          <p className="text-2xl font-bold">{weather.feelsLikeF}°</p>
        </div>

        <div className="bg-white/10 rounded-xl p-4">
          <p className="text-gray-300">Humidity</p>
          <p className="text-2xl font-bold">{weather.humidity}%</p>
        </div>

        <div className="bg-white/10 rounded-xl p-4 col-span-2">
          <p className="text-gray-300">Wind</p>
          <p className="text-2xl font-bold">{weather.windSpeedMph} mph</p>
        </div>
      </div>
    </div>
  );
}

export default WeatherCard;
