interface WeatherInfoCardProps {
  icon: React.ReactNode;
  title: string;
  value: string;
}

function WeatherInfoCard({ icon, title, value }: WeatherInfoCardProps) {
  return (
    <div
      className="
        bg-white/10
        rounded-2xl
        p-4
        text-center
        transition
        duration-300
        ease-in-out
        hover:bg-black
        hover:scale-105
        hover:shadow-xl
      "
    >
      <div className="flex justify-center mb-2">{icon}</div>

      <p className="text-sm text-gray-300">{title}</p>

      <p className="text-2xl font-bold">{value}</p>
    </div>
  );
}

export default WeatherInfoCard;
